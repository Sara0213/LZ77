#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
const int window_size = 255;
void compress(string input_file, string output_file)
{
deque<char> window;
deque<char> bufor;
ifstream fin(input_file);
ofstream fout(output_file);
for (int i = 0; i < window_size; i++)
window.push_back(0);
while (!fin.eof() and bufor.size() <= window_size)
{
char c = fin.get();
if (!fin.eof())
bufor.push_back(c);
}
while (bufor.size() > 0)
{
int best_start = 0;
int best_len = 0;
for (int j = 0; j < window_size; j++)
{
int len = 0;
while (len + 1 < bufor.size() and j + len < window_size and
window[j + len] == bufor[len])
len++;
if (len > best_len)
{
best_len = len;
best_start = j;
}
}
fout << (unsigned char)best_start << (unsigned char)best_len
<< bufor[best_len];
for (int i = 0; i <= best_len; i++)
{
window.push_back(bufor[0]);
window.pop_front();
bufor.pop_front();
}
while (!fin.eof() and bufor.size() <= window_size)
{
char c = fin.get();
if (!fin.eof())
bufor.push_back(c);
}
}
}
void decompress(string input_file, string output_file)
{
deque<char> window;
deque<char> bufor;
ifstream fin(input_file);
ofstream fout(output_file);
for (int i = 0; i < window_size; i++)
window.push_back(0);
unsigned char start = fin.get();
unsigned char len = fin.get();
char c = fin.get();
while (!fin.eof())
{
for (int i = 0; i < len; i++)
{
window.push_back(window[start + i]);
fout << window[start+i];
}
window.push_back(c);
fout << c;
while (window.size() > window_size)
window.pop_front();
start = fin.get();
len = fin.get();
c = fin.get();
}
}
int main(int argc, char** argv)
{
if (argc != 4)
{
cout << "Użycie:" << endl;
cout << "Kompresja: " << argv[0] << " -c plik_wejsciowy
plik_wyjsciowy" << endl;
cout << "Dekompresja: " << argv[0] << " -d plik_wejsciowy plik
wyjsciowy" << endl;
return 1;
}
if (argv[1][1] == 'c')
compress(argv[2], argv[3]);
else
decompress(argv[2], argv[3]);
return 0;
}
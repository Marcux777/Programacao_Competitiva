#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int vis[50][50];
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[0].size(); j++)
            {
                vis[i][j] = false;
            }
        }
        int corinicial = image[sr][sc];
        floodfill(image, sr, sc, image.size(), image[0].size(), color, corinicial);
        return image;
    }
    void floodfill(vector<vector<int>> &image, int x, int y, int linha, int coluna, int cor, int corinic)
    {
        if (x < 0 || y < 0 || x >= linha || y >= coluna || vis[x][y] || image[x][y] != corinic)
        {
            return;
        }
        if (image[x][y] == corinic)
        {
            image[x][y] = cor;
            vis[x][y] = true;
        }
        floodfill(image, x + 1, y, linha, coluna, cor, corinic);
        floodfill(image, x, y + 1, linha, coluna, cor, corinic);
        floodfill(image, x - 1, y, linha, coluna, cor, corinic);
        floodfill(image, x, y - 1, linha, coluna, cor, corinic);
    }
};

int main()
{
    // Exemplo de uso
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    for (auto linha : image)
    {
        for (auto pixel : linha)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution solucao;
    vector<vector<int>> novaImagem = solucao.floodFill(image, sr, sc, newColor);
    for (auto linha : novaImagem)
    {
        for (auto pixel : linha)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}

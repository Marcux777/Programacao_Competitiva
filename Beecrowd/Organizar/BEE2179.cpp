#include <iostream>
#include <vector>
using namespace std;
int cont = 0;
void turn_left(int &r, int &c)
{
    c -= 1;
}
void turn_right(int &r, int &c)
{
    c += 1;
}
void turn_up(int &r, int &c)
{
    r -= 1;
}
void turn_down(int &r, int &c)
{
    r += 1;
}
bool is_outside(int row, int col,
                int r, int c)
{
    cont++;
    if (r >= row || c >= col || r < 0 || c < 0)
        return true;
    return false;
}
void next_turn(char &previous_direction,
               int &r, int &c)
{
    if (previous_direction == 'u')
    {
        cont++;
        turn_right(r, c);
        previous_direction = 'r';
    }
    else if (previous_direction == 'r')
    {
        cont++;
        turn_down(r, c);
        previous_direction = 'd';
    }
    else if (previous_direction == 'd')
    {
        cont++;
        turn_left(r, c);
        previous_direction = 'l';
    }
    else if (previous_direction == 'l')
    {
        cont++;
        turn_up(r, c);
        previous_direction = 'u';
    }
}
void move_in_same_direction(
    char previous_direction,
    int &r, int &c)
{
    cont++;
    if (previous_direction == 'r')
        c++;
    else if (previous_direction == 'u')
        r--;
    else if (previous_direction == 'd')
        r++;
    else if (previous_direction == 'l')
        c--;
}

vector<vector<int>> spiralMatrix(
    int rows, int cols, int r, int c)
{
    vector<vector<int>> res;
    char previous_direction = 'r';
    int turning_elements = 2;
    int count = 0;
    int current_count = 0;
    int turn_count = 0;
    int limit = rows * cols;

    while (count < limit)
    {
        if (!is_outside(rows, cols, r, c))
        {
            res.push_back({r, c});
            count++;
        }
        current_count++;
        if (current_count == turning_elements)
        {
            turn_count++;

            if (turn_count == 2)
                turning_elements++;

            else if (turn_count == 3)
            {
                turn_count = 1;
            }

            next_turn(previous_direction, r, c);
            current_count = 1;
        }
        else
        {
            move_in_same_direction(
                previous_direction, r, c);
        }
        cont++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int N, F, C;
    cin >> N >> F >> C;
    vector<vector<int>> mat(N, vector<int>(N));
    int cont = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = cont++;
        }
    }
    vector<vector<int>> final = spiralMatrix(N, N, F, C);
    vector<int> resp;
    for (auto it : final)
    {
        resp.push_back(mat[it[0]][it[1]]);
    }
    for (int i = 0; i < resp.size(); i++)
    {
        cout << resp[i];
        if (i < resp.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    cout << cont - 1 << endl;
    return 0;
}

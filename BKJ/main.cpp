#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct cell
{
        int ptr;
        string value = "EMPTY";
};

int Find(int i);
void Union(int i, int j);
void Update(vector<string>& cmd);
void Merge(vector<string>& cmd);
void UnMerge(vector<string>& cmd);
void Print(vector<string>& cmd);
vector<string> split(string cmd);

vector<cell> table;
vector<string> answer;

vector<string> solution(vector<string> commands) {
        table.resize(50 * 50);
        for (int i = 0; i < table.size(); i++)
                table[i].ptr = i;

        for (string c : commands)
        {
                vector<string> cmd = split(c);

                if (cmd[0] == "UPDATE")
                        Update(cmd);
                else if (cmd[0] == "MERGE")
                        Merge(cmd);
                else if (cmd[0] == "UNMERGE")
                        UnMerge(cmd);
                else if (cmd[0] == "PRINT")
                        Print(cmd);

        }
        return answer;
}

void Update(vector<string>& cmd)
{
        if (cmd.size() == 3)
        {
                for (cell& c : table) {
                        int idx = Find(c.ptr);
                        if (table[idx].value == cmd[1])
                                table[idx].value = cmd[2];
                }
        }
        else
        {
                int r = stoi(cmd[1]) - 1;
                int c = stoi(cmd[2]) - 1;

                int idx = Find(r * 50 + c);
                table[idx].value = cmd[3];
        }
}

void Merge(vector<string>& cmd)
{
        int r1 = stoi(cmd[1]) - 1;
        int c1 = stoi(cmd[2]) - 1;
        int r2 = stoi(cmd[3]) - 1;
        int c2 = stoi(cmd[4]) - 1;

        int idx1 = (r1 * 50) + c1;
        int idx2 = (r2 * 50) + c2;

        Union(idx1, idx2);
}

void UnMerge(vector<string>& cmd)
{
        int r = stoi(cmd[1]) - 1;
        int c = stoi(cmd[2]) - 1;

        int idx = (r * 50) + c;
        int root = Find(idx);
        string value = table[root].value;

        vector<int> targets;
        for (int i = 0; i < table.size(); i++)
        {
                if (Find(table[i].ptr) == root)
                        targets.push_back(i);
        }

        for (int i : targets)
        {
                table[i].ptr = i;
                table[i].value = "EMPTY";
        }

        table[idx].value = value;
}

void Print(vector<string>& cmd)
{
        int r = stoi(cmd[1]) - 1;
        int c = stoi(cmd[2]) - 1;

        int idx = Find(r * 50 + c);
        answer.push_back(table[idx].value);
}


int Find(int i)
{
        if (table[i].ptr == i)
                return i;

        return table[i].ptr = Find(table[i].ptr);
}

void Union(int i, int j)
{
        i = Find(i);
        j = Find(j);

        if (table[i].value == "EMPTY" && table[j].value != "EMPTY")
        {
                table[i].ptr = j;
        }
        else
                table[j].ptr = i;
}

vector<string> split(string cmd)
{
        vector<string> result;
        string str;
        for (char c : cmd) {
                if (c == ' ') {
                        result.push_back(str);
                        str = "";
                        continue;
                }
                str.push_back(c);
        }
        result.push_back(str);
        return result;
}



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
    node *left;
    node *right;
    char val;
    int freq;
    string symbol;
};

struct binarytree
{
    node *bt;
    int size;

    binarytree(node *t, int s)
    {
        bt = t;
        size = s;
    }
};

struct priorityqueue
{
    node *pq;
    int size;

    priorityqueue(node *q, int s)
    {
        pq = q;
        size = s;
    }

    void Insert(node *w)
    {
        size++;
        pq[size - 1].left = w->left;
        pq[size - 1].right = w->right;
        pq[size - 1].val = w->val;
        pq[size - 1].freq = w->freq;
        pq[size - 1].symbol = w->symbol;
        int v = size;

        while ((v > 1) && (pq[(v / 2) - 1].freq > pq[v - 1].freq))
        {
            node tmp = pq[v - 1];
            pq[v - 1] = pq[(v / 2) - 1];
            pq[(v / 2) - 1] = tmp;
            v = v / 2;
        }
    }

    void BuildMinHeap()
    {
        for (int j = size / 2; j >= 1; j--)
        {
            MinHeapify(j);
        }
    }

    node * ExtractMin()
    {
        node *min = (node *) malloc(sizeof(*min));
        min->left = pq[0].left;
        min->right = pq[0].right;
        min->val = pq[0].val;
        min->freq = pq[0].freq;
        min->symbol = pq[0].symbol;
        pq[0] = pq[size - 1];
        size--;

        MinHeapify(1);

        return min;
    }

    void MinHeapify(int i)
    {
        int l = 2 * i;
        int r = (2 * i) + 1;
        int smallest = i;

        if ((l <= size) && (pq[l - 1].freq < pq[i - 1].freq))
        {
            smallest = l;
        }

        if ((r <= size) && (pq[r - 1].freq < pq[smallest - 1].freq))
        {
            smallest = r;
        }

        if (smallest != i)
        {
            node tmp = pq[i - 1];
            pq[i - 1] = pq[smallest - 1];
            pq[smallest - 1] = tmp;

            MinHeapify(smallest);
        }
    }
};

struct huff
{
    string input, output;

    huff(string i)
    {
        input = i;
    }

    string decode()
    {
        binarytree T(NULL, 0);

        T.bt = decodetree(NULL);

        if (input[0] == '\n')
        {
            input.erase(0, 1);
        }

        node *pos = T.bt;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '\n')
            {
                output += '\n';
            }
            else if (input[i] == '0')
            {
                pos = pos->left;
            }
            else
            {
                pos = pos->right;
            }

            if (pos->val > -1)
            {
                output += pos->val;
                pos = T.bt;
            }
        }

        return output;
    }

    node * decodetree(node *curr)
    {
        if (input[0] == '1')
        {
            input.erase(0, 1);

            curr = (node *) malloc(sizeof(*curr));
            curr->left = NULL;
            curr->right = NULL;
            curr->val = input[0];
            curr->freq = -1;
            curr->symbol = "";

            input.erase(0, 1);
        }
        else
        {
            input.erase(0, 1);

            curr = (node *) malloc(sizeof(*curr));
            curr->left = NULL;
            curr->right = NULL;
            curr->val = -1;
            curr->freq = -1;
            curr->symbol = "";
            curr->left = decodetree(curr->left);
            curr->right = decodetree(curr->right);
        }

        return curr;
    }

    string encode()
    {
        int *freqs = (int *) calloc(256, sizeof(*freqs));

        if (freqs == NULL)
        {
            cout << "Memory allocation failed. Program may crash. Press enter to continue." << endl;
            cin.get();
        }

        int n = 0;
        node *c;

        for (int i = 0; i < input.size(); i++)
        {
            freqs[input[i]]++;
        }

        for (int i = 0; i < 256; i++)
        {
            if ((freqs[i] != 0) && (i != '\n'))
            {
                n++;
                c = (node *) realloc(c, n * sizeof(*c));

                if (c == NULL)
                {
                    cout << "Memory allocation failed. Program may crash. Press enter to continue." << endl;
                    cin.get();
                }

                c[n - 1].left = NULL;
                c[n - 1].right = NULL;
                c[n - 1].val = i;
                c[n - 1].freq = freqs[i];
                c[n - 1].symbol = "";
            }
        }

        free(freqs);
        freqs = NULL;

        return Huffman(c, n);
    }

    string Huffman(node *C, int N)
    {
        priorityqueue Q(C, N);
        binarytree T(C, N);

        Q.BuildMinHeap();

        while (Q.size > 1)
        {
            node *z = (node *) malloc(sizeof(*z));

            if (z == NULL)
            {
                cout << "Memory allocation failed. Program may crash. Press enter to continue." << endl;
                cin.get();
            }

            node *x = z->left = Q.ExtractMin();
            node *y = z->right = Q.ExtractMin();
            z->freq = x->freq + y->freq;
            z->val = -1;
            z->symbol = "";

            Q.Insert(z);

            T.size++;
        }

        T.bt = Q.ExtractMin();

        fillsymbols(T.bt, "");

        encodetree(T.bt);

        output += '\n';

        for (int i = 0; i < input.size(); i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (input[i] == C[j].val)
                {
                    output += C[j].symbol;

                    break;
                }
                else if (input[i] == '\n')
                {
                    output += '\n';

                    break;
                }
            }
        }

        return output;
    }

    void fillsymbols(node *curr, string symb)
    {
        if (curr->val > -1)
        {
            curr->symbol = symb;
        }
        else
        {
            fillsymbols(curr->left, symb + "0");
            fillsymbols(curr->right, symb + "1");
        }
    }

    void encodetree(node *curr)
    {
        if (curr->val > -1)
        {
            output += "1";
            output += curr->val;
        }
        else
        {
            output += "0";

            encodetree(curr->left);
            encodetree(curr->right);
        }
    }
};

int main(int argc, char *argv[])
{
    string in, line;
    string argv1 = argv[1];
    string hufargv2 = argv[2];
    hufargv2 += ".huf";

    if (argc == 3)
    {
        if (argv1.compare("encode") == 0)
        {
            ifstream ifile(argv[2]);

            if (ifile.is_open())
            {
                ofstream ofile(hufargv2.c_str(), ios::out | ios::trunc);

                while (!ifile.eof())
                {
                    getline(ifile, line);

                    in += line;
                    in += '\n';
                }

                huff h(in);

                ofile << h.encode();

                ifile.close();
                ofile.close();
            }
        }
        else if (argv1.compare("decode") == 0)
        {
            ifstream ifile(hufargv2.c_str());

            if (ifile.is_open())
            {
                ofstream ofile(argv[2], ios::out | ios::trunc);

                while (!ifile.eof())
                {
                    getline(ifile, line);

                    in += line;
                    in += '\n';
                }

                huff h(in);

                ofile << h.decode();

                ifile.close();
                ofile.close();
            }
        }
    }

    return 0;
}
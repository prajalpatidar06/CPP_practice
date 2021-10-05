#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    bool imposter;
    node *left, *right;
    node(int data, bool imposter = false)
    {
        this->data = data;
        this->imposter = imposter;
        left = right = 0;
    }
};

int solve(int &maxi, node *tree){
    if(!tree){
        return 0;
    }
    int curr = 0;
    if(tree->imposter){
        solve(maxi,tree->left);
        solve(maxi,tree->right);
    }
    else{
        curr += solve(maxi,tree->left);
        curr += solve(maxi,tree->right);
    }
    maxi = max(curr,maxi);
    return curr;
}

node* maketree(node *tree, int i, vector<pair<int, int>> v, vector<int> imp_idx)
{
    if (i >= v.size())
        return NULL;
    int src = v[i].first;
    int child = v[i].second;
    bool imposter = (imp_idx[src] == 1);
    if (!tree)
    {
        tree = new node(src,imposter);
        tree->left = new node(child,0);
    }
    else
    {
        if (src != tree->data)
        {
            if (tree->left && tree->left->data == src)
            {
                tree = tree->left;
            }
            else
            {
                tree = tree->right;
            }
        }
        if (tree->left)
        {
            tree->right = new node(child, imposter);
        }
        else
        {
            tree->left = new node(child, imposter);
        }
    }
    maketree(tree, i + 1, v, imp_idx);
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    int imposter;
    cin >> imposter;
    vector<int> imp_idx(n + 1, 0);
    for (int i = 0; i < imposter; i++)
    {
        cin >> a;
        imp_idx[a] = 1;
    }
    node *tree = NULL;
    maketree(tree,0,v,imp_idx);
    int maxi = 0;
    solve(maxi , tree);
    cout<<maxi;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node
{
public:
    int val;
    node* next;
    int freq = 0;
};

node* head = NULL;
node* tail = NULL;

node* findxnode(int x)
{
    node* p = head;
    while (p)
    {
        if (p->val == x)
            return p;
        p = p->next;
    }
    return NULL;
}
node* findynode(int y)
{
    node* p = head;
    if(p->val==y)
    return p;
    while (p->next)
    {
        if (p->next->val == y)
            return p;
        p = p->next;
    }
    return NULL;
}

node* findmid(int x, int y)
{
    node* p = head;
    while (p)
    {
        if (p->val == x)
            break;
        p = p->next;
    }
    if (p->next->val == y)
        return p;
    node* q = p->next->next;
    while (q->next->val != y)
    {
        q = q->next->next;
        p = p->next;
    }
    return p->next;
}

int main()
{
    int n;
    cin >> n;
    vector<node*> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        vector<int> arr;
        char a;
        cin >> a;
        s = s + a;
        if (a == 'I')
        {
            char b;
            cin >> b;
            s = s + b;
            if (b == '0')
            {
                for (int l = 0; l < 1; l++)
                {
                    int pq;
                    cin >> pq;
                    arr.push_back(pq);
                }
            }
            if (b == '1')
            {
                for (int l = 0; l < 2; l++)
                {
                     int pq;
                    cin >> pq;
                    arr.push_back(pq);
                }
            }
            if (b == '2')
            {
                for (int l = 0; l < 3; l++)
                {
                    int pq;
                    cin >> pq;
                    arr.push_back(pq);
                }
            }
        }
        else if(a=='U')
        {
                int pq, dq;
                cin >> pq >> dq;
                arr.push_back(pq);
                arr.push_back(dq);
        }
        if (s[0] == 'I')
        {
            if (s[1] == '0')
            {
                if (head == NULL)
                {
                    node* newnode = new node();
                    newnode->val = arr[0];
                    newnode->next = NULL;
                    head = newnode;
                    tail = newnode;
                    v.push_back(newnode);
                }
                else
                {
                    node* newnode = new node();
                    tail->next = newnode;
                    tail = newnode;
                    tail->val = arr[0];
                    tail->next = NULL;
                    tail->freq++;
                    v.push_back(newnode);
                }
            }
            else if (s[1] == '1')
            {
                int x = arr[0];
                int y = arr[1];
                node* xn = findxnode(x);
                if (xn)
                {
                    node* newnode = new node();
                    newnode->next = xn->next;
                    xn->next = newnode;
                    newnode->val = y;
                    newnode->freq++;
                    v.push_back(newnode);
                    if (newnode->next == NULL)
                        tail = newnode;
                }
                else
                {
                    node* yn = findynode(y);
                    if(yn!=head){
                    node* newnode = new node();
                    newnode->next = yn->next;
                    yn->next = newnode;
                    newnode->val = x;
                    newnode->freq++;
                    v.push_back(newnode);
                    }
                    if(yn==head){
                        node* newnode=new node();
                        newnode->next=head;
                        head=newnode;
                        newnode->val=x;
                        v.push_back(newnode);
                    }
                }
            }
            else if (s[1] == '2')
            {
                node* mid = findmid(arr[0], arr[1]);
                node* newnode = new node();
                newnode->next = mid->next;
                mid->next = newnode;
                newnode->val = arr[2];
                newnode->freq++;
                v.push_back(newnode);
            }
        }
        else if (s[0] == 'U')
        {
            node* xn = findxnode(arr[0]);
            node* y = xn;
            int count = 0;
            while (count < (arr[1]))
            {
                if (xn->next)
                {
                    xn = xn->next;
                    count++;
                }
                else if (!xn->next)
                {
                    xn->next = head;
                    head->freq++;
                    xn = xn->next;
                    count++;
                }
            }
            y->next->freq--;
            y->next = xn;
            xn->freq++;
        }
        s.erase();
        arr.clear();
    }
    if (head->freq > 0)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->freq > 1)
            count++;
    }
    cout << count << endl;
    vector<int> bat;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->freq > 1)
            bat.push_back(v[i]->val);
    }
    if (bat.size() == 0)
    {
        node* p = head;
        while (p != tail)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << p->val << endl;
    }
    else {
        sort(bat.begin(), bat.end());
        for (int i = 0; i < bat.size(); i++)
            cout << bat[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < bat.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j]->val == bat[i])
                cout << v[j]->freq << " ";
        }
    }
    cout << endl;

}
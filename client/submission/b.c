#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
    long long val;
    node* next;
    long long freq = 0;
};

node* head = NULL;
node* tail = NULL;

node* findxnode(long long x)
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
node* findynode(long long y)
{
    node* p = head;
    if (p->val == y)
        return p;
    while (p->next)
    {
        if (p->next->val == y)
            return p;
        p = p->next;
    }
    return NULL;
}

node* findmid(long long x, long long y)
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
    long long n;
    cin >> n;
    vector<node*> v;
    long long i = 0;
    while (i < n)
    {
        string s;
        vector<long long> arr;
        char a;
        cin >> a;
        s = s + a;
        switch(a)
        {
            { case 'I':
            char b;
            cin >> b;
            s = s + b;
            switch (b) {
                
                {   case '0':
                    long long l = 0;
                    while (l < 1)
                    {
                        long long pq;
                        cin >> pq;
                        arr.push_back(pq);
                        l++;
                    }
                    break;
                }
                {   case '1':
                    long long l = 0;
                    while (l < 2)
                    {
                        long long pq;
                        cin >> pq;
                        arr.push_back(pq);
                        l++;
                    }
                    break;
                }
                {   case '2':
                    long long l = 0;
                    while (l < 3)
                    {
                        long long pq;
                        cin >> pq;
                        arr.push_back(pq);
                        l++;
                    }
                    break;
                }
            }
            break;
            }
           {   case 'U':
            long long pq, dq;
            cin >> pq >> dq;
            arr.push_back(pq);
            arr.push_back(dq);
            break;
           }
        }
        switch (s[0]) {
            {   case 'I':
                switch (s[1]) {
                    {   case '0':
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
                        break;
                    }
                    {   case '1':
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
                            if (yn != head) {
                                node* newnode = new node();
                                newnode->next = yn->next;
                                yn->next = newnode;
                                newnode->val = x;
                                newnode->freq++;
                                v.push_back(newnode);
                            }
                            if (yn == head) {
                                node* newnode = new node();
                                newnode->next = head;
                                head = newnode;
                                newnode->val = x;
                                v.push_back(newnode);
                            }
                        }
                        break;
                    }
                    {   case '2':
                        node* mid = findmid(arr[0], arr[1]);
                        node* newnode = new node();
                        newnode->next = mid->next;
                        mid->next = newnode;
                        newnode->val = arr[2];
                        newnode->freq++;
                        v.push_back(newnode);
                        break;
                    }
                }
                break;
            }
            {   case 'U':
                node * xn = findxnode(arr[0]);
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
                break;
            }
        }
        s.erase();
        arr.clear();
        i++;
    }
    switch (head->freq) {
        {   case 0:
            cout << "0" << endl;
            break; }
        {default:
            cout << "0" << endl;
            break; }
    }
    long long count = 0;
    i = 0;
    while(i < v.size())
    {
        if (v[i]->freq > 1)
            count++;
        i++;
    }
    cout << count << endl;
    vector<long long> bat;
    i = 0;
    while( i < v.size())
    {
        if (v[i]->freq > 1)
            bat.push_back(v[i]->val);
        i++;
    }
    switch (bat.size()) {
        {   case 0:
            node* p = head;
            while (p != tail)
            {
                cout << p->val << " ";
                p = p->next;
            }
            cout << p->val << endl;
            break;
        }
         { default:
            sort(bat.begin(), bat.end());
            for (int m = 0; m < bat.size(); m++)
                cout << bat[m] << " ";
            break;
         }
    }
    cout << endl;
    i = 0;
    while( i < bat.size())
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j]->val == bat[i])
                cout << v[j]->freq << " ";
        }
        i++;
    }
    cout << endl;

}

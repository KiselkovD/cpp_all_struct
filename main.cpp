#include <iostream>
//#define otlad
using std::cout;
using std::cin;
using std::endl;

typedef int dat_t;
#define TYP1 dmas
class dmas////////////////////////////////////////////////////////////////////////
{
public:
    int m_siz=0;
    dat_t *p_mas=NULL;
    /*
    dmas()
    ~dmas()
    void newsiz(int x);
    */
    dmas()
    {
#ifdef otlad
        cout << "(dmas dmas)\n";
#endif
        dat_t *p_mas = new dat_t[m_siz];
    }
    ~dmas()
    {
#ifdef otlad
        cout << "(dmas ~dmas)\n";
#endif
        delete [] p_mas;
    }
    void newsiz(int x)
    {
#ifdef otlad
        cout << "(dmas newsiz)\n";
#endif
        if (x!=m_siz)
        {
            if(x<m_siz)
            {
                cout << " no newsiz(< m_siz) \n";
            }
            else
            {

                dat_t *p_mas2 = new dat_t[x];
                for (int i=0; i<m_siz; i++) p_mas2[i]=p_mas[i];
                delete [] p_mas;
                p_mas=p_mas2;
                m_siz=x;
            }
        }
    }
};

class stak ///////////////////////////////////////////////////////////////////////
{
    dmas mas;
    int poz=0;
public:
    /*
    stak()
    int empt()
    int ful()
    void put(dat_t x)
    dat_t get()
    dat_t look()
    void newsiz(int x)
    */
    stak()
    {
#ifdef otlad
        cout << "(stak stak)\n";
#endif
        mas.newsiz(1);
    }
    int empt()
    {
#ifdef otlad
        cout << "(stak empt)\n";
#endif
        if (poz==0)
        {
            return 1;
        }
        else return 0;
    }
    int ful()
    {
#ifdef otlad
        cout << "(stak ful)\n";
#endif
        if (poz==mas.m_siz-1 || mas.m_siz<2)
        {
            return 1;
        }
        else return 0;
    }
    void put(dat_t x)
    {
#ifdef otlad
        cout << "(stak put)\n";
#endif
        if (ful())
        {
            cout << " no put \n";
        }
        else
        {
            mas.p_mas[poz]=x;
            poz++;
        }
    }
    dat_t get()
    {
#ifdef otlad
        cout << "(stak get)\n";
#endif
        if (empt())
        {
            cout << " no get \n";
            return 0;
        }
        else
        {
            poz--;
            return mas.p_mas[poz];
        }
    }
    dat_t look()
    {
#ifdef otlad
        cout << "(stak look)\n";
#endif
        if (empt())
        {
            cout << " no look \n";
            return 0;
        }
        else
        {
            return mas.p_mas[poz-1];
        }
    }
    void newsiz(int x)
    {
#ifdef otlad
        cout << "(stak newsiz)\n";
#endif
        mas.newsiz(x);
    }

};

class que ////////////////////////////////////////////////////////////////////////
{
    dmas mas;
    int poz1=0,poz2=0;
public:
    /*
    que()
    int empt()
    int ful()
    void put(dat_t x)
    dat_t get()
    dat_t look()
    int newsiz(int x)
    */
    que()
    {
#ifdef otlad
        cout << "(que que)\n";
#endif
        mas.newsiz(1);
    }
    int empt()
    {
#ifdef otlad
        cout << "(que empt)\n";
#endif
        if (poz1==poz2)
        {
            return 1;
        }
        else return 0;
    }
    int ful()
    {
#ifdef otlad
        cout << "(que ful)\n";
#endif
        if (poz1-poz2==1 || poz2-poz1==mas.m_siz-1 || mas.m_siz<2)
        {
            return 1;
        }
        else return 0;
    }
    void put(dat_t x)
    {
#ifdef otlad
        cout << "(que put)\n";
#endif
        if (ful())
        {
            cout << " no put \n";
        }
        else
        {
            if (poz2==mas.m_siz-1)
            {
                mas.p_mas[poz2]=x;
                poz2=0;
            }
            else
            {
                mas.p_mas[poz2]=x;
                poz2++;
            }
        }
    }
    dat_t get()
    {
#ifdef otlad
        cout << "(que get)\n";
#endif
        if (empt())
        {
            cout << " no get \n";
            return 0;
        }
        else
        {
            if (poz1==mas.m_siz-1)
            {
                poz1=0;
                return mas.p_mas[mas.m_siz-1];
            }
            else
            {
                poz1++;
                return mas.p_mas[poz1-1];
            }
        }
    }
    dat_t look()
    {
#ifdef otlad
        cout << "(que look)\n";
#endif
        if (empt())
        {
            cout << " no get \n";
            return 0;
        }
        else
        {
            return mas.p_mas[poz1];
        }
    }
    int newsiz(int x)
    {
#ifdef otlad
        cout << "(que newsiz)\n";
#endif
        if (poz1<=poz2)
        {
            mas.newsiz(x);
            return 1;
        }
        else
        {
            cout << " no newsiz \n";
            return 0;
        }
    }
};

class dek ////////////////////////////////////////////////////////////////////////
{
    dmas mas;
    int poz1=0,poz2=1;
public:
    /*
    dek()
    int empt()
    int ful()
    void put1(dat_t x)
    void put2(dat_t x)
    dat_t get1()
    dat_t get2()
    dat_t look1()
    dat_t look2()
    int newsiz(int x)
    */
    dek()
    {
#ifdef otlad
        cout << "(dek dek)\n";
#endif
        mas.newsiz(2);
    }
    int empt()
    {
#ifdef otlad
        cout << "(dek empt)\n";
#endif
        //cout << "  empt dek\n";
        if (poz2-poz1==1 || poz1-poz2==mas.m_siz-1)
        {
            return 1;
        }
        else return 0;
    }
    int ful()
    {
#ifdef otlad
        cout << "(dek ful)\n";
#endif
        //cout << "  ful dek\n";
        if (poz1-poz2==1 || poz2-poz1==mas.m_siz-1 || mas.m_siz<3)
        {
            return 1;
        }
        else return 0;
    }
    void put1(dat_t x)
    {
#ifdef otlad
        cout << "(dek put1)\n";
#endif
        //cout << "  put1 dek\n";
        if (ful())
        {
            cout << " no put1 \n";
        }
        else
        {
            if (poz1==0)
            {
                mas.p_mas[poz1]=x;
                poz1=mas.m_siz-1;
            }
            else
            {
                mas.p_mas[poz1]=x;
                poz1--;
            }
        }
    }
    void put2(dat_t x)
    {
#ifdef otlad
        cout << "(dek put2)\n";
#endif
        //cout << "  put2 dek\n";
        if (ful())
        {
            cout << " no put2 \n";
        }
        else
        {
            if (poz2==mas.m_siz-1)
            {
                mas.p_mas[poz2]=x;
                poz2=0;
            }
            else
            {
                mas.p_mas[poz2]=x;
                poz2++;
            }
        }
    }
    dat_t get1()
    {
#ifdef otlad
        cout << "(dek get1)\n";
#endif
        //cout << "  get1 dek\n";
        if (empt())
        {
            cout << " no get1 \n";
            return 0;
        }
        else
        {
            if (poz1==mas.m_siz-1)
            {
                poz1=0;
                return mas.p_mas[poz1];
            }
            else
            {
                poz1++;
                return mas.p_mas[poz1];
            }
        }
    }
    dat_t get2()
    {
#ifdef otlad
        cout << "(dek get2)\n";
#endif
        //cout << "  get2 dek\n";
        if (empt())
        {
            cout << " no get2 \n";
            return 0;
        }
        else
        {
            if (poz2==0)
            {
                poz2=mas.m_siz-1;
                return mas.p_mas[poz2];
            }
            else
            {
                poz2--;
                return mas.p_mas[poz2];
            }
        }
    }
    dat_t look1()
    {
#ifdef otlad
        cout << "(dek look1)\n";
#endif
        //cout << "  look1 dek\n";
        if (empt())
        {
            cout << " no look1 \n";
            return 0;
        }
        else
        {
            if (poz1==mas.m_siz-1)
            {
                return mas.p_mas[0];
            }
            else
            {
                return mas.p_mas[poz1+1];
            }
        }
    }
    dat_t look2()
    {
#ifdef otlad
        cout << "(dek look2)\n";
#endif
        //cout << "  look2 dek\n";
        if (empt())
        {
            cout << " no look2 \n";
            return 0;
        }
        else
        {
            if (poz2==0)
            {
                return mas.p_mas[mas.m_siz-1];
            }
            else
            {
                return mas.p_mas[poz2-1];
            }
        }
    }
    int newsiz(int x)
    {
#ifdef otlad
        cout << "(dek newsiz)\n";
#endif
        //cout << "  newsiz dek\n";
        if (poz1<poz2)
        {
            mas.newsiz(x+2);
            return 1;
        }
        else
        {
            cout << " no newsiz \n";
            return 0;
        }
    }
};

class spisok
{
public:
    dat_t data;
    spisok* next;

    spisok* new_node(spisok* beg,int nod_num);
    void change(spisok* beg,dat_t x,int nod_num);
    spisok* del(spisok* beg,int nod_num);
    dat_t look(spisok* beg,int nod_num);
    int find_last (spisok* beg);
};

spisok* new_node(spisok* beg,int nod_num)
{

    spisok* temp = new spisok;
    temp->next = NULL;
    temp->data = -1;
    if (nod_num!=0)
    {
        spisok* tempbeg=beg;


        int flag=1;
        if (tempbeg==NULL) flag=0;
        for (int i=0; i<nod_num-1; i++)
        {
            if (flag==0 || tempbeg->next==NULL)
            {
                flag=0;
            }
            else
            {
                tempbeg = tempbeg->next;
            }
        }

        if (tempbeg==NULL)
        {

            flag=0;
        }
            if(flag==1)
        {

            if (tempbeg->next != NULL)
            {
                temp->next = tempbeg->next;
                tempbeg->next = temp;
            }
            else
            {
                tempbeg->next =temp;
            }

        }
        else
            {
                cout<<"(haven't so many node)\n";
            delete temp;

            }
            return beg;
    }
    else
    {
        if (beg!=NULL)
        {
            temp->next=beg;
        }
        return temp;
    }


}
void change(spisok* beg,dat_t x,int nod_num)
{
    spisok* tempbeg;
    if (nod_num!=0)
    {
        spisok* tempbeg=beg;

        int flag=1;
        if (tempbeg==NULL) flag=0;

        for (int i=0; i<nod_num-1; i++)
        {
            if (flag==0 ||tempbeg->next==NULL)
            {
                flag=0;
            }
            else
            {
                tempbeg = tempbeg->next;
            }
        }
        if (tempbeg->next==NULL)flag=0;

        if(flag==1)
        {
            tempbeg->next->data=x;
        }
        else
        {
            cout<<"(its no exist (change))\n";

        }

    }
    else
    {
        if (beg!=NULL)
        {
            beg->data=x;
        }
        else
        {
            cout<<"(its no exist (change))\n";

        }
    }
}
spisok* del(spisok* beg,int nod_num)
{
    if (beg!=NULL)
    {
    if (nod_num!=0)
    {
        spisok* tempbeg=beg;


        int flag=1;
        if (tempbeg==NULL) flag=0;
        for (int i=0; i<nod_num-1; i++)
        {
            if (flag==0 || tempbeg->next==NULL)
            {
                flag=0;
            }
            else
            {
                tempbeg = tempbeg->next;
            }
        }

        if (tempbeg==NULL)
        {
            flag=0;
        }
        if(flag==1)
        {
            if (tempbeg->next->next!=NULL)
            {
                spisok* temp2=tempbeg->next->next;
                delete tempbeg->next;
                tempbeg->next=temp2;
            }
        else
        {
           delete tempbeg->next;
            tempbeg->next=NULL;
        }
        return beg;
        }
        else
        {
            cout<<"(its no exist (del))\n";
            return beg;
        }
    }
    else
    {
        if (beg->next!=NULL)
        {
            spisok* temp2=beg->next;
            delete beg;
            beg=temp2;
        }
        else
        {
            delete beg;
            beg=NULL;
        }
        return beg;
    }
    }
    else
    {
        cout<<"(its no exist (del))\n";
        return beg;
    }

}
dat_t look(spisok* beg,int nod_num)
{
    if (nod_num!=0)
    {
        int flag=1;
        if (beg==NULL) flag=0;
        for (int i=0; i<nod_num; i++)
        {
            if (flag==0 || beg->next==NULL)
            {
                flag=0;
            }
            else
            {
                beg=beg->next;
            }
        }
        if(flag)
        {
            return beg->data;
        }
        else
        {
            cout<<"(its no exist (look))\n";
            return -1;
        }
    }
    else
    {
        if (beg!=NULL)
        {
            return beg->data;
        }
        else
        {
            cout<<"(its no exist (look))\n";
            return -1;
        }
    }
}
int find_last (spisok* beg)
{
if (beg==NULL)
{
    return -1;
}
else
{
    int i=0;
    while (beg->next!=NULL)
    {
        i++;
        beg=beg->next;
    }
    return i;
}
}
void free (spisok* beg)
{
    if (beg!=NULL)
    {

    while (beg->next!=NULL)
        {
            spisok* temp2=beg->next;
            delete beg;
            beg=temp2;
        }
        delete beg;
        beg=NULL;
    }

}

class spisok_first_node
{
public:
    spisok* first;
    ~spisok_first_node()
    {
        free(first);
    }
};

class spisok2_node
{
public:
    dat_t data;
    spisok2_node* next;
    spisok2_node* prev;
};
/*class spisok2
{
    public:
    spisok2_node* first,last;

    /*spisok2* new_node(spisok2* beg_,int start_from,int nod_num);
    void change(spisok2* beg,int start_from,dat_t x,int nod_num);
    spisok2* del(spisok2* beg,int start_from,int nod_num);
    dat_t look(spisok2* beg,int start_from,int nod_num);*/

    /*spisok2 new_node(spisok2* beg,int start_from,int nod_num)//start_from 0- beg else end
    {
        if (start_from==0)
        {
            beg
        }
        else
        {

        }
        spisok2_node* temp = new spisok2_node;
        temp->next = NULL;
        temp->prev = NULL
        temp->data = -1;
        if (nod_num!=0)
        {
            spisok* tempbeg=beg;


            int flag=1;
            if (tempbeg==NULL) flag=0;
            for (int i=0; i<nod_num-1; i++)
            {
                if (flag==0 || tempbeg->next==NULL)
                {
                    flag=0;
                }
                else
                {
                    tempbeg = tempbeg->next;
                }
            }

            if (tempbeg==NULL)
            {

                flag=0;
            }
                if(flag==1)
            {

                if (tempbeg->next != NULL)
                {
                    temp->next = tempbeg->next;
                    tempbeg->next = temp;
                }
                else
                {
                    tempbeg->next =temp;
                }

            }
            else
                {
                    cout<<"(haven't so many node)\n";
                delete temp;

                }
                return beg;
        }
        else
        {
            if (beg!=NULL)
            {
                temp->next=beg;
            }
            return temp;
        }


    }
};*/


int main()
{

    /*dek q1;
    q1.newsiz(4);
    q1.put1(5);
    q1.put1(5);
    cout << q1.get2();
    q1.put1(5);
    q1.newsiz(4);
    cout <<".";
    q1.put1(5);
    q1.put1(5);*/
    spisok_first_node q1;
    q1.first =NULL;
    cout << find_last(q1.first);
    q1.first = new_node(q1.first,0);
    //q1.first
    cout<<find_last(q1.first);
    q1.first = new_node(q1.first,1);
    cout<<find_last(q1.first);
    q1.first = new_node(q1.first,1);
    cout<<find_last(q1.first);

    //free(q1);








    return 0;

}

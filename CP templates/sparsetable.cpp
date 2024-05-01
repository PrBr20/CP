template <class T>
class STable
{
    int n;
    pair<int,int> *cal;
    vector<T> *SparseTable;
    T (*comp)(T,T);
    void initialize()
    {
        int i,j;
        cal[1].second=1;
        for(i=1,j=1<<i; j<=n; i++,j=1<<i)
        {
            cal[j].first=1;
            cal[j].second=j;
        }
        for(i=2; i<=n; i++)
        {
            cal[i].first=cal[i].first+cal[i-1].first;
            if(cal[i].second==0) cal[i].second=cal[i-1].second;
        }
    }
public:
    STable(vector<T> &arr,T (*f)(T,T))
    {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++)
        {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j)
        {
            for(i=0; i+m<n; i++)
            {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    }
    T query(int l,int r)
    {
        int difference=(r-l+1);
        return comp(SparseTable[l][cal[difference].first],SparseTable[r-cal[difference].second+1][cal[difference].first]);
    }
    ~STable()
    {
        int i;
        for(i=0;i<n;i++)
        {
            SparseTable[i].clear();
        }
        delete []SparseTable;
        delete []cal;
        comp=0;
    }
};
int minimum(int a,int b){
    if( a< b ) return a;
    else return b;
}
int maximum(int a,int b){
    if( a> b ) return a;
    else return b;
}

STable<int> segMax(ara,maximum);
STable<int> segMin(bara,minimum);
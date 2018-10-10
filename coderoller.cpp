#include <iostream>
using namespace std;

int main()
{
    int L;
    int C;
    int N;
    cin >> L >> C >> N; cin.ignore();
    
    int p[N];
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        p[i] = Pi;
    }
  
	int argentStocke[1000]={0};
	int numDeGrpgStocke[N];
	int nbreDeTour = 0;
	int grpAMonter = 0;
	long long dirhams = 0;
	int i = 0;
	
	while (nbreDeTour!=C)

	{
		
		grpAMonter = 0;
		int iCount = 0;
		int iPred = i;

		if (argentStocke[i] != 0)
		{
				if (grpAMonter + argentStocke[i] <= L)
				{
					dirhams += argentStocke[i];
					i = (i + numDeGrpgStocke[i]) % N;
					nbreDeTour++;
					continue;
				}
		}
		while (i < N)
		{


			if (iCount >= N)
			{
				break;
			}
			if (p[i] + grpAMonter <= L)
			{
				grpAMonter += p[i];
			}
			else
			{
				break;
			}
			i++;
			iCount++;
			if (i == N)
			{
				i = 0;
			}
		}
		argentStocke[iPred] = grpAMonter;
		numDeGrpgStocke[iPred] = iCount;
		dirhams += grpAMonter;
		nbreDeTour++;
	}

    cout << dirhams << endl;
}
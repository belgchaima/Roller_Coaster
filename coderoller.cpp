#include <iostream>
using namespace std;

int main()
{
  
    int N , grpAMonter =0;
	long long L, C,
	nbreDeTour,
	argentStocke[1000]={ 0 },
	numDeGrpgStocke[1000][2]={{0}},
	dirhams = 0;
    cin >> L >> C >> N ; cin.ignore();
    for (int i = 0; i < N; ++i)  cin >> numDeGrpgStocke[i][0]; cin.ignore();
	
	for (nbreDeTour=0 ; nbreDeTour<C ; ++nbreDeTour){
	
		if (numDeGrpgStocke[grpAMonter][1] !=0) break; 
		numDeGrpgStocke[grpAMonter][1] = nbreDeTour;		
		int groupe=grpAMonter ;
	    long long l = 0;
		do{
		
		  if(l+numDeGrpgStocke[grpAMonter][0]> L) break; 
		  l += numDeGrpgStocke[grpAMonter++][0];
		  if (grpAMonter==N ) grpAMonter = 0;
		} while(grpAMonter!= groupe) ;
        dirhams += (argentStocke[nbreDeTour] = l);
	} 
		
		if (nbreDeTour < C)
		{
			long long iCount = nbreDeTour;
            long long iPred = numDeGrpgStocke[grpAMonter][1];
            long long tourC = iCount - iPred;
            long long gainC = 0; 
            long long nbrTourC = (C - nbreDeTour)/tourC;
            long long i;
        for(i=iPred; i< iCount; ++i) gainC += argentStocke[i];
        dirhams += gainC*nbrTourC;
		nbreDeTour += tourC*nbrTourC;
        for(;nbreDeTour<C;++nbreDeTour) dirhams += argentStocke[(nbreDeTour-iCount)%tourC+iPred];		
		}

    cout << dirhams << endl;
}
/////////////////////////////////
//this will generate/////////////
//random numbs for diff decays///
/////////////////////////////////
#include<iostream>
using namespace std;

//setting the hypothesisH0 for X-Sig[0]+Del[1] 

int setH0(double number_H0){

if(number_H0<0.5) //making equipropbable
return 0;

else 
return 1;
}

//setting the hypothesisH1 for X-Sig+Del
int setH1(double number_H1){

if(number_H1<0.35) //making sigmas less probable
return 0;

else 

return 1;
}

//func to generate alpha, beta, gamma from Sigma 

int getSigmaDecay(double mynum){

if(0<mynum  && mynum<=0.33333) //This decay ch assigns equal probability
	return 1; //1 is alpha 
else if(0.33333<mynum && mynum<=0.66666)
	return 2; //2 is beta
else 
	return 3; //3 is gamma

}

//func to generate alpha, beta, gamma from Delta 

int getDeltaDecay(double mynumb){

if(0<mynumb  && mynumb<=0.255555) //This decay ch produces more beta's
        return 1; //1 is alpha 
else if(0.255555<mynumb && mynumb<=0.78888)
        return 2; //2 is beta
else

        return 3; //3isgamma
}

//main function
void doDecays(int numRuns){

	//storing the data for first decay processes

	ofstream xdecay_H0;
        xdecay_H0.open("xdecayH0.txt");
        ofstream xdecay_H1;
        xdecay_H1.open("xdecayH1.txt");

//trandom class to generate rndm numbers(RN)
TRandom3 *rnd = new TRandom3();
double num=0;
int num_H0[numRuns];
int  num_H1[numRuns];
int SigResult_H0=0, SigResult_H1=0;
int DelResult_H0=0, DelResult_H1=0;
//loops starts for x->sig/Del
for (int i=0; i<=numRuns; i++){

	 num = rnd->Rndm(i);
  //cout<<num<<endl;
//call func for x->Sig/Delta for H0 
  num_H0[i] = setH0(num);

 //call func for x->Sig/Delta for H1 
  num_H1[i] = setH1(num);

  //cout<<num_H0[i]<<"   : "<<num_H1[i]<<endl;
}

//Sig/delta->alpha/beta/gamma

for(int j=0; j<=numRuns; j++){

	double rn = rnd->Rndm(j);

	//cal func Sig decay in H0
    if(num_H0[j]==0){
     	SigResult_H0 = getSigmaDecay(rn);
    }//cal func for Delta decay
    else if(num_H0[j]==1){  DelResult_H0 = getDeltaDecay(rn);
    }
     //  cout<<"based on H0    "<<SigResult_H0<< " : "<<DelResult_H0<<endl;

     xdecay_H0<<SigResult_H0<<" "<<DelResult_H0<<endl;//storing the data in the file
    //cal func for Sig decay in H1

     if(num_H1[j]==0){
     
	     SigResult_H1 = getSigmaDecay(rn);
     }
     else if(num_H1[j]==1){
     
	     DelResult_H1 = getDeltaDecay(rn);
     }

     cout<<"basad on H1     "<<SigResult_H1<<"   : "<<DelResult_H1<<endl;

 xdecay_H1<<SigResult_H1<<" "<<DelResult_H1<<endl;//storing the data in the file
}//loop closed

xdecay_H0.close();//files closed
xdecay_H1.close();

}

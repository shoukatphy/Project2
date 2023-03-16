/////////////////////////////////
//this will generate/////////////
//random numbs for diff decays///
/////////////////////////////////
#include<iostream>

using namespace std;


//setting the hypothesisH0 for X-Sig[0]+Del[1] 

int setH0(double number_H0){

if(0<number_H0 && number_H0<0.5) //making equipropbable
return 0;

else if(0.5<number_H0 && number_H0<1)
return 1;

else

return 6;//an unidentified particle

}


//setting the hypothesisH1 for X-Sig+Del

int setH1(double number_H1){

if(0<number_H1 && number_H1<0.6) //making sigmas less probable
return 0;

else if(0.6<number_H1 && number_H1<1) 

return 1;
else 
	return 6;//an un-indentified particle
}

//func to generate alpha, beta, gamma from Sigma 

int getSigmaDecay(double mynum){

if(0<mynum  && mynum<=0.3) //This decay ch assigns equal probability
	return 1; //1 is alpha 
else if(0.3<mynum && mynum<=0.7)
	return 2; //2 is beta
else 
	return 3; //3 is gamma

}

//func to generate alpha, beta, gamma from Delta 

int getDeltaDecay(double mynumb){

if(0<mynumb  && mynumb<=0.3) //This decay ch produces more beta's
        return 1; //1 is alpha 
else if(0.3<mynumb && mynumb<=0.6)
        return 2; //2 is beta
else

        return 3; //3isgamma

}


//main function
void doDecays(int numRuns){

	//storing the data in files for x-decays

	ofstream xdecay_H0;
        xdecay_H0.open("xdecayH0.txt");
        ofstream xdecay_H1;
        xdecay_H1.open("xdecayH1.txt");

	//for Sigma/Delta decays
	ofstream sigDec_H0;
	sigDec_H0.open("sigdecayH0.txt");
	ofstream sigDec_H1;
	sigDec_H1.open("sigdecayH1.txt");
	
	ofstream delDec_H0;
        delDec_H0.open("deldecayH0.txt");
        ofstream delDec_H1;
        delDec_H1.open("deldecayH1.txt");

//trandom class to generate rndm numbers(RN)
TRandom3 *rnd = new TRandom3();
TTimeStamp *tm = new TTimeStamp();//to get the independent random numbers
double num=0;
int num_H0[numRuns];
int  num_H1[numRuns];
int SigResult_H0=0, SigResult_H1=0;
int DelResult_H0=0, DelResult_H1=0;
//loops starts for x->sig/Del
for (int i=1; i<=numRuns+1; i++){


	 num = rnd->Rndm(i);
  //cout<<num<<endl;
//call func for x->Sig/Delta for H0 
  num_H0[i] = setH0(num);


 //call func for x->Sig/Delta for H1 
  num_H1[i] = setH1(num);

  //cout<<num_H0[i]<<"   : "<<num_H1[i]<<endl;
xdecay_H0 << num_H0[i]<<endl; //storing the data for xdeay based on H0
xdecay_H1 << num_H1[i]<<endl; //based on H1

}

//Sig/delta->alpha/beta/gamma

for(int j=1; j<=numRuns+1; j++){

	double rn = rnd->Rndm(tm->GetNanoSec());//GetNanoSec()

	//cal func Sig decay in H0
    if(num_H0[j]==0){
     	SigResult_H0 = getSigmaDecay(rn);
    }//cal func for Delta decay
    else if(num_H0[j]==1){  
	    DelResult_H0 = getDeltaDecay(rn);
    }
     //  cout<<"based on H0    "<<SigResult_H0<< " : "<<DelResult_H0<<endl;
   
 sigDec_H0<< SigResult_H0<<endl; //storing data for sig/del decays 
 delDec_H0<< DelResult_H0<<endl;

       
     //cal func for Sig decay in H1

     if(num_H1[j]==0){
     
	     SigResult_H1 = getSigmaDecay(rn);
     }
     else if(num_H1[j]==1){
     
	     DelResult_H1 = getDeltaDecay(rn);
     }

     cout<<"basad on H1     "<<SigResult_H1<<"   : "<<DelResult_H1<<endl;

 sigDec_H1<<SigResult_H1<<endl;//storing data for sig/del for H1 
 delDec_H1<<DelResult_H1<<endl;


}//loop closed


xdecay_H0.close();//files closed
xdecay_H1.close();
sigDec_H0.close();
delDec_H0.close();
sigDec_H1.close();
delDec_H1.close();


delete rnd;
delete tm;

}//end

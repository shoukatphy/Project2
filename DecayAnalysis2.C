////////////////////////
//Decay analysis ///////
//of two set of decays//
//LLR///////////////////
#include<iostream>
using namespace std;


int DecayAnalysis2(const int nmEvents){

        //open all the data files 
	
	ifstream x_H0("xdecayH0.txt");//for x-sigDel

	if(!x_H0.is_open()){

	cout<< "Error opening the  xdecayH0 file"<<endl;

	}

	ifstream x_H1("xdecayH1.txt");

        if(!x_H1.is_open()){

        cout<< "Error opening the  xdecay file"<<endl;

        }


	 ifstream sig_H0("sigdecayH0.txt");//for sig-alphabetagamma

        if(!sig_H0.is_open()){

        cout<< "Error opening the  sigmaH0 file"<<endl;

        }

        ifstream sig_H1("sigdecayH1.txt");

        if(!sig_H1.is_open()){

        cout<< "Error opening the  sigdecayH1 file"<<endl;

        }
	
	ifstream del_H0("deldecayH0.txt");//for delta-alphabetagamma

        if(!del_H0.is_open()){

        cout<< "Error opening the  deltaH0 file"<<endl;

        }

        ifstream del_H1("deldecayH1.txt");

        if(!del_H1.is_open()){

        cout<< "Error opening the  deltadecayH1 file"<<endl;

        }
         //arrays to store the data

	int xH0_arr[nmEvents], xH1_arr[nmEvents], sigH0_arr[nmEvents], sigH1_arr[nmEvents], delH0_arr[nmEvents], delH1_arr[nmEvents];
       
       for(int r=0; r<nmEvents; r++){
       
       x_H0>>xH0_arr[r];//xdecay data array
       x_H1>>xH1_arr[r];

       sig_H0>>sigH0_arr[r];//sig decay data array
       sig_H1>>sigH1_arr[r];

       del_H0>>delH0_arr[r];//delta decay data array
       del_H1>>delH1_arr[r];


       }//array loop closed	
 //cout<<delH0_arr[4]<<delH1_arr[6]<<sigH0_arr[7]<<sigH0_arr[3]<<xH0_arr[2]<<endl;
       //prob distri for x-sigdel based on H1/H2
double numDelH0=0, numDelH1=0;
double numSigH0=0, numSigH1=0;

//double SigprobH0, DelprobH0;
for(int k=0; k<nmEvents; k++){
   
	if(xH0_arr[k]==0){
	numSigH0++;
	}
       
	else if(xH0_arr[k]==1){
	
	numDelH0++;
	}
	else{
	cout<<"we have an un-indentified particle in the detector"<<endl;
	}
} 

//for H1 hypo
for(int l=0; l<nmEvents; l++){

	  if(xH1_arr[l]==0){
        numSigH1++;
        }
        else if(xH1_arr[l]==1){
        numDelH1++;
        }

	  else{
	  cout<<"There is an unindentified particle in the detector"<<endl;
	  }
}
double SigprobH0 = numSigH0/nmEvents;
double DelprobH0 = numDelH0/nmEvents;


double SigprobH1 = numSigH1/nmEvents;
double DelprobH1 = numDelH1/nmEvents;

cout<<SigprobH1<<" xH1 "<<DelprobH1<<endl;
double xinH0[2] = {SigprobH0, DelprobH0};
double xinH1[2] = {SigprobH1, DelprobH1};
double  particles[2] = {0., 1.};//0for sig and 1for delta
cout<<xinH0[0]<<"and "<<xinH0[1]<<endl;
   
double numAlpha_H0=0, numBeta_H0=0, numGamma_H0=0;
double numAlpha_H1=0, numBeta_H1=0, numGamma_H1=0;

double prob_AlphaH0=0, prob_BetaH0=0, prob_GammaH0=0;
double prob_AlphaH1=0, prob_BetaH1=0, prob_GammaH1=0;

double LLR_H0; //loglikelihood ratio
double LLR_H1;

//hisogram for LLR_H0 and LLR_H1
auto *llrH0 = new TH1D("llrH0", "H0 LLR", 10, -3.5, 3.5);
auto *llrH1 = new TH1D("llrH1", "H1 LLR", 10, -3.5, 3.5);
int run=50;
int Entries=1;
while(Entries<=run){

for(int m=0; m<Entries; m++){

	//num of alpha beta and gamma particles 
	if(sigH0_arr[m]==1 || delH0_arr[m]==1){
	
	numAlpha_H0++; 
	}

	else if(sigH0_arr[m]==2 || delH0_arr[m]==2){
	
	
		numBeta_H0++;
	}
	else if(sigH0_arr[m]==3 || delH0_arr[m]==3){
	
	
		numGamma_H0++;
	}
      
	else{
	cout<<"There is an un-identified particle in the detector"<<endl;
	}

}
// H1 case gives

for(int n=0; n<nmEvents; n++){

	  if(sigH1_arr[n]==1 || delH1_arr[n]==1){

                numAlpha_H1++;
        }

        else if(sigH1_arr[n]==2 || delH1_arr[n]==2){

                numBeta_H1++;
        }

        else if(sigH1_arr[n]==3 || delH1_arr[n]==3){
        numGamma_H1++;
        }
        else{
        cout<<"There is an un-identified particle in the detector"<<endl;
        }
}

 cout<<"H0: alpha "<<numAlpha_H0<<" beta "<<numBeta_H0<<" gamma "<<numGamma_H0<<endl;
 cout<<"H1: alpha "<<numAlpha_H1<<" beta "<<numBeta_H1<<" gamma "<<numGamma_H1<<endl;
 prob_AlphaH0= numAlpha_H0/nmEvents;//probabilities based on H0
 prob_BetaH0 = numBeta_H0/nmEvents;
 prob_GammaH0 = numGamma_H0/nmEvents;

 prob_AlphaH1 = numAlpha_H1/nmEvents;
 prob_BetaH1 = numBeta_H1/nmEvents;
 prob_GammaH1 = numGamma_H1/nmEvents;
 
 cout<< "probH0"<<prob_GammaH0<<endl; 
 cout<<" probH1 "<<prob_GammaH1<<endl;


LLR_H0= (numAlpha_H0*TMath::Log(prob_AlphaH0/prob_AlphaH1))*(numBeta_H0*TMath::Log(prob_BetaH0/prob_BetaH1))*(numGamma_H0*TMath::Log(numGamma_H0/numGamma_H1))/(Entries*1000000000);

LLR_H1= (numAlpha_H1*TMath::Log(prob_AlphaH0/prob_AlphaH1))*(numBeta_H1*TMath::Log(prob_BetaH0/prob_BetaH1))*(numGamma_H1*TMath::Log(numGamma_H0/numGamma_H1))/(Entries*1000000000000);

llrH0->Fill(LLR_H0);
llrH1->Fill(LLR_H1);
cout<<"log likelihood ratio H0/H1 "<<LLR_H0<< " / "<<LLR_H1<<endl;
Entries++;
}

auto *hs = new THStack("hs","Log Likelyhood Ratios; Runs(Experiments); LLR");


//creat canvas 
auto *cn = new TCanvas();
auto *gr_xH0 = new TGraph(2, particles,xinH0 ); 
auto *gr_xH1 = new TGraph(2, particles, xinH1);
cn->Divide(2, 1);
cn->cd(1);
gr_xH0->SetFillColor(2);
gr_xH0->SetTitle("X->Sigma+Delta Decay based on H0");
gr_xH0->GetXaxis()->SetTitle("particles(0=sigma, 1=delta))"); //giving titles to axis
gr_xH0->GetYaxis()->SetTitle("Probability distribution");
gr_xH0->Draw("AB");

cn->cd(2);
gr_xH1->SetFillColor(3);
gr_xH1->SetTitle("X->Sigma+Delta Decay based on H1");
gr_xH1->GetXaxis()->SetTitle("particles(0=sigma, 1=delta))"); //giving titles to axis
gr_xH1->GetYaxis()->SetTitle("Probability distribution");
gr_xH1->Draw("AB");

//cn->cd(3);

/*
llrH0->SetMarkerStyle(23);
llrH0->SetLineColor(3);
llrH0->SetFillColor(4);
//llrH0->Draw();

//cn->cd(4);
llrH1->SetMarkerStyle(25);
llrH1->SetLineColor(2);
llrH1->SetFillColor(6);

//llrH1->Draw();

//for LLR
hs->Add(llrH0);
hs->Add(llrH1);
hs->SetTitle("Histogram for Log Likelyhood Ratios; LLR; Runs(No.of Experiments)");
hs->Draw();

auto *l = new TLegend(0.6 ,0.6, 0.9 ,0.9);

l->AddEntry("llrH0", "H0 Hypothesis");
l->AddEntry("llrH1", "H1 Hypothesis");
l->Draw();

*/





cn->SaveAs("Prob_proj2.pdf");
return 0;
}//end

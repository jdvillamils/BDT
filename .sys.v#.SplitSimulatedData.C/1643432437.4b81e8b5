#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <time.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <iostream>
#include <stdio.h>

int SplitSimulatedData(void){
 
    TChain* sigchain = new TChain("Signal");
    TChain* bacchain = new TChain("Background");
    bacchain->AddFile("RootFiles/background.root");
    sigchain->AddFile("RootFiles/signal.root");
    
    Float_t mlls;
    Float_t mllb;
    Float_t leads;
    Float_t leadb;
    Float_t subleads;
    Float_t subleadb;
    Float_t weights;
    Float_t weightb;
    sigchain->SetBranchAddress("mll", &mlls);
    sigchain->SetBranchAddress("lead", &leads);
    sigchain->SetBranchAddress("sublead", &subleads);
    sigchain->SetBranchAddress("weight", &weights);
    
    bacchain->SetBranchAddress("mll", &mllb);
    bacchain->SetBranchAddress("lead", &leadb);
    bacchain->SetBranchAddress("sublead", &subleadb);
    bacchain->SetBranchAddress("weight", &weightb);
    
    TFile *target = new TFile("RootFiles/simulated.root","RECREATE");
    
    TTree *sigtest = new TTree("SignalTest","Signal for test");
    TTree *backtest = new TTree("BackgroundTest","Background for test");
    TTree *sigtrain = new TTree("SignalTrain","Signal for train");
    TTree *backtrain = new TTree("BackgroundTrain","Background for train");
    
     Float_t mllste;
    Float_t mllbte;
    Float_t leadste;
    Float_t leadbte;
    Float_t subleadste;
    Float_t subleadbte;
    Float_t weightste;
    Float_t weightbte;
    Float_t mllstr;
    Float_t mllbtr;
    Float_t leadstr;
    Float_t leadbtr;
    Float_t subleadstr;
    Float_t subleadbtr;
    Float_t weightstr;
    Float_t weightbtr;
    
    sigtest->Branch("mll", &mllste);
    sigtest->Branch("lead", &leadste);
    sigtest->Branch("sublead", &subleadste);
    sigtest->Branch("weight", &weightste);
    sigtrain->Branch("mll", &mllstr);
    sigtrain->Branch("lead", &leadstr);
    sigtrain->Branch("sublead", &subleadstr);
    sigtrain->Branch("weight", &weightstr);
    
    backtest->Branch("mll", &mllbte);
    backtest->Branch("lead", &leadbte);
    backtest->Branch("sublead", &subleadbte);
    backtest->Branch("weight", &weightbte);
    backtrain->Branch("mll", &mllbtr);
    backtrain->Branch("lead", &leadbtr);
    backtrain->Branch("sublead", &subleadbtr);
    backtrain->Branch("weight", &weightbtr);
    
    int nentries, nbytes, k;
    int counter1=0

    nentries = (Int_t)sigchain->GetEntries();
    for (k = 0; k < nentries; k++)
    {
        nbytes = sigchain->GetEntry(k);
        counter1++;
        //fill 33% for training
        if(counter1==1)
        {
            mllstr=mlls;
            leadstr=leads;
            subleadstr=subleads;
            weightstr=weights;
            sigtrain->Fill();
        }
        if(counter1==2)
        {
            mllste=mlls;
            leadste=leads;
            subleadste=subleads;
            weightste=weights;
            sigtest->Fill();
        }
        if(counter1==3)
        {
            mllste=mlls;
            leadste=leads;
            subleadste=subleads;
            weightste=weights;
            sigtest->Fill();
            counter1==0;
        }
        
    }
    
    int nentriesb, nbytesb, j;
    int counter2=0;

    nentriesb = (Int_t)bacchain->GetEntries();
    for (j = 0; j < nentriesb; j++)
    {
        nbytesb = bacchain->GetEntry(j);
        counter2++;
        if(counter2==1)
        {
            mllbtr=mllb;
            leadbtr=leadb;
            subleadbtr=subleadb;
            weightbtr=weightb;
            backtrain->Fill();
        }
        if(counter2==2)
        {
            mllbte=mllb;
            leadstb=leadb;
            subleadstb=subleadb;
            weightstb=weightb;
            backtest->Fill();
        }
        if(counter2==3)
        {
            mllbte=mllb;
            leadbte=leadb;
            subleadbte=subleadb;
            weightbte=weightb;
            backtest->Fill();
            counter2==0;
        }
    }
    sigtest->Write();
    backtest->Write();
    sigtrain->Write();
    backtrain->Write();
    target->Close();
    return 0;

}
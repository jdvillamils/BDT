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
 
    TChain* sigchain = new TChain("signal");
    TChain* bacchain = new TChain("background");
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
    
    TFile *target = new TFile("RootFiles/splitMC.root","RECREATE");
    
    TTree *mctest = new TTree("MCTest","MC for test");
    TTree *sigtrain = new TTree("SignalTrain","Signal for train");
    TTree *backtrain = new TTree("BackgroundTrain","Background for train");
    TTree *sigtest = new TTree("SignalTest", "Signal for testing");
    TTree *backtest = new TTree("BackgroundTest", "Background for test");
    
    Float_t mllte;
    Float_t leadte;
    Float_t subleadte;
    Float_t weightte;
    Float_t weightbte;
    Float_t mllstr;
    Float_t mllbtr;
    Float_t leadstr;
    Float_t leadbtr;
    Float_t subleadstr;
    Float_t subleadbtr;
    Float_t weightstr;
    Float_t weightbtr;
    Float_t mllste;
    Float_t mllbte;
    Float_t leadste;
    Float_t leadbte;
    Float_t subleadste;
    Float_t subleadbte;
    Float_t weightste;
    
    mctest->Branch("mll", &mllte);
    mctest->Branch("lead", &leadte);
    mctest->Branch("sublead", &subleadte);
    mctest->Branch("weight", &weightte);
    sigtrain->Branch("mll", &mllstr);
    sigtrain->Branch("lead", &leadstr);
    sigtrain->Branch("sublead", &subleadstr);
    sigtrain->Branch("weight", &weightstr);
    backtrain->Branch("mll", &mllbtr);
    backtrain->Branch("lead", &leadbtr);
    backtrain->Branch("sublead", &subleadbtr);
    backtrain->Branch("weight", &weightbtr);
    sigtest->Branch("mll", &mllste);
    sigtest->Branch("lead", &leadste);
    sigtest->Branch("sublead", &subleadste);
    sigtest->Branch("weight", &weightste);
    backtest->Branch("mll",  &mllbte);
    backtest->Branch("lead",  &leadbte);
    backtest->Branch("sublead",  &subleadbte);
    backtest->Branch("weight",  &weightbte);
    
    int nentries, nbytes, k;
    int counter1=0;

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
            mllte=mlls;
            mllste=mlls;
            leadte=leads;
            leadste=leads;
            subleadte=subleads;
            subleadste=subleads;
            weightte=weights;
            weightste=weights;
            mctest->Fill();
            sigtest->Fill();
        }
        if(counter1==3)
        {
            mllte=mlls;
            mllste=mlls;
            leadte=leads;
            leadste=leads;
            subleadte=subleads;
            subleadste=subleads;
            weightte=weights;
            weightste=weights;
            mctest->Fill();
            sigtest->Fill();
            counter1=0;
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
            mllte=mllb;
            mllste=mllb;
            leadte=leadb;
            leadbte=leadb;
            subleadte=subleadb;
            subleadbte=subleadb;
            weightte=weightb;
            weightbte=weightb;
            mctest->Fill();
            backtest->Fill();
        }
        if(counter2==3)
        {
            mllte=mllb;
            mllste=mllb;
            leadte=leadb;
            leadbte=leadb;
            subleadte=subleadb;
            subleadbte=subleadb;
            weightte=weightb;
            weightbte=weightb;
            mctest->Fill();
            backtest->Fill();
            counter2=0;
        }
    }
    mctest->Write();
    sigtrain->Write();
    backtrain->Write();
    sigtest->Write();
    backtest->Write();
    target->Close();
    return 0;

}
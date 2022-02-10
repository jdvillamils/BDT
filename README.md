# Analysis of Z Boson production using TMVA  and PyROOT.

## Introduction

In this work, we use [PyROOT](https://root.cern/manual/python/) and [ROOT](https://root.cern.ch/) to analyse the production of [Z Boson in the two lepton final state](http://opendata.atlas.cern/release/2020/documentation/physics/DL1.html) using the available data from [Atlas Open Data](http://opendata.atlas.cern). Also, we make use of [TMVA](https://root.cern/manual/tmva/), to identify and discriminate the signal and background of the decay.

## Analysis

With the criteria described in AOD web, simulated samples corresponding to the signal, are processed so that, a clean signal output is obtanied and saved in a root file. For simulated background a similar process is done, taking from the samples the relevant events.

Once  this is done, we split and organize tha data, in order to be processed by the TMVA, which returns back root files with the information of the bdt discriminant.

Final step is plotting the variables, making cuts on the bdt value, to reduce the amount of background and compare it with data with no sa cuts.

## Files in this Repo
+  Z-Boson-MAin-Analysis.ipynb is where all the data cleaning for signal, background and data is done.  
+ SplitSimulatedData.C organizes the resulting root files, split a portion of simulated data for training and other for testing.
+ TMVA files, train and test the BDT
+ The Classifier notebook uses a fraction of data in SciKit to return a first basic analysis of the behavior of bdt value.

## To run

For the analysis, you have two options:
- Download the already processed and trained files, using the command
```
source download_root_files.sh 
```
This will create a folder containing different root files ready for being plotted.

- Second option is to run the Z-Boson-MAin-Analysis.ipynb. This may take some time depending on your machine. You may break the loop after a fraction of events to reduce time.

When its ready, run 
```
source run.sh 
```
and you will have the files ready to be plotted in BDTAnalysis.ipynb

Clearly, if you need to change anything in the processing section, you will need to run the main analysis.

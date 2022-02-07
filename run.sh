echo Getting the data ready

root -q SplitSimulatedData.C

echo Training and testing TMVA

root -q TMVAClassification.C

root -q TMVAClassificationApplication.C

root -q TMVAClassificationApplicationData.C
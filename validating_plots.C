#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include "TROOT.h"
#include <math.h> 

void validating_plots(){

  
  TFile *file = new TFile;
  
  TTree *Events = new TTree;
  TTree *Events2 = new TTree;
  TTree *Events3 = new TTree;
  TTree *Events4 = new TTree;
  TTree *Events5 = new TTree;
  TTree *Events6 = new TTree;
  TTree *Events7 = new TTree;
  TTree *Events8 = new TTree;
  TTree *Events9 = new TTree;
  TTree *Events10 = new TTree;
  TTree *Events11 = new TTree;
  TTree *Events12 = new TTree;
  TTree *Events13 = new TTree;
  TTree *Events14 = new TTree;
  TTree *Events15 = new TTree;
  
  //TTree *h1 = new TTree;
  
   
  TCanvas *c1 = new TCanvas("name","title",800,800);
  
  file = TFile::Open("/exp/dune/app/users/nbostan/protoduneana/protoduneana/singlephase/Analysis/ntuple_sets/prod_beam_p1GeV_cosmics_protodunehd_20240402T230743Z_188238_000255_g4_stage1_g4_stage2_sce_E500_detsim_reco_pdhd_ntuple_1.root", "READ");
  
  Events = (TTree*)file->Get("pduneana/beamana");
  Events2 = (TTree*)file->Get("pduneana/beamana");
  Events3 = (TTree*)file->Get("pduneana/beamana");
  Events3 = (TTree*)file->Get("pduneana/beamana");
  Events4 = (TTree*)file->Get("pduneana/beamana");
  Events5 = (TTree*)file->Get("pduneana/beamana");
  Events6 = (TTree*)file->Get("pduneana/beamana");
  Events7 = (TTree*)file->Get("pduneana/beamana");
  Events8 = (TTree*)file->Get("pduneana/beamana");
  Events9 = (TTree*)file->Get("pduneana/beamana");
  Events10 = (TTree*)file->Get("pduneana/beamana");
  Events11 = (TTree*)file->Get("pduneana/beamana");
  Events12 = (TTree*)file->Get("pduneana/beamana");
  Events13 = (TTree*)file->Get("pduneana/beamana");
  Events14 = (TTree*)file->Get("pduneana/beamana");
  Events15 = (TTree*)file->Get("pduneana/beamana");
  
  
  TFile *fout = new TFile("pdune_hd_analysis.root","RECREATE");
  gStyle->SetPalette(1);
 
 
   
  Events->Draw("true_beam_endZ>>hist1(100,All,All");
 
 
   TH1F * hist1 = (TH1F*)gDirectory->Get("hist1");
   gStyle->SetPalette(1);
   hist1->SetFillColor(6);
   hist1->SetXTitle ("true_beam_endZ");
   hist1->SetYTitle ("Number of Events");
   hist1->SetTitle("DUNE: ProtoDUNE-HD");
   //hist1->Fit("gaus");
   hist1->Write();
   
    Events2->Draw("reco_beam_endZ>>hist2(100,All,All");
   

   TH1F * hist2 = (TH1F*)gDirectory->Get("hist2");
   gStyle->SetPalette(2);
   hist2->SetFillColor(4);
   hist2->SetXTitle ("reco_beam_endZ");
   hist2->SetYTitle ("Number of Events");
   //hist2->Fit("gaus");
   hist2->SetTitle("DUNE: ProtoDUNE-HD");
   //gStyle->SetPalette(1);

   hist2->Write();
   
   Events3->Draw("reco_beam_startZ>>hist3(100,-20,80");
   
   TH1F * hist3 = (TH1F*)gDirectory->Get("hist3");
   gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist3->SetXTitle ("reco_beam_startZ [cm]");
   hist3->SetYTitle ("Number of Events");
   //hist3->Fit("gaus");
   hist3->SetTitle("DUNE: ProtoDUNE-HD");
   //gStyle->SetPalette(1);

   hist3->Write();

  Events33->Draw("reco_beam_startZ>>hist33(100,-20,80");
   
   TH1F * hist33 = (TH1F*)gDirectory->Get("hist33");
   hist33->Scale(1.0/hist33->Integral()) //Area normalization for reco beam startZ
   gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist33->SetXTitle ("reco_beam_startZ [cm]");
   hist33->SetYTitle ("Number of Events");
   //hist3->Fit("gaus");
   hist33->SetTitle("DUNE: ProtoDUNE-HD");
   //gStyle->SetPalette(1);

   hist33->Write();
   
   
   
   Events4->Draw("reco_beam_endY:reco_beam_endX>>hist4(1000,All,All,1000,All,All","","COLZ");
   

   TH2F * hist4 = (TH2F*)gDirectory->Get("hist4");
   gPad->SetLogz();
   //gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist4->SetXTitle ("reco beam end X [cm]");
   hist4->SetYTitle ("reco beam end Y [cm]");
   hist4->SetStats(0);
   //hist2->Fit("gaus");
   hist4->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files, no Z cut");
   gStyle->SetPalette(1);

   hist4->Write();
   
   Events5->Draw("reco_beam_endY:reco_beam_endX>>hist5(1000,-400,400,1000,0,600","","COLZ");
   
   TH2F * hist5 = (TH2F*)gDirectory->Get("hist5");
   //gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist5->SetXTitle ("reco beam end X [cm]");
   hist5->SetYTitle ("reco beam end Y [cm]");
   gPad->SetLogz();
   hist5->SetStats(0);
   //hist2->Fit("gaus");
   hist5->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files, no Z cut");
   gStyle->SetPalette(1);

   hist5->Write();
   
   Events6->Draw("reco_beam_endX:reco_beam_endZ>>hist6(1000,0,600,1000,-400,400","","COLZ");
   
   TH2F * hist6 = (TH2F*)gDirectory->Get("hist6");
   //gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist6->SetXTitle ("reco beam end Z [cm]");
   hist6->SetYTitle ("reco beam end X [cm]");
   gPad->SetLogz();
   hist6->SetStats(0);
   //hist2->Fit("gaus");
   hist6->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files, no Z cut");
   gStyle->SetPalette(1);

   hist6->Write();
   
   Events7->Draw("reco_beam_dEdX_SCE:reco_beam_resRange_SCE>>hist7(500,0,250,160,0,4","","COLZ");
   
   TH2F * hist7 = (TH2F*)gDirectory->Get("hist7");
   //gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist7->SetXTitle ("residual range [cm], sce corr");
   hist7->SetYTitle ("dE/dX [MeV/cm], sce corr");
   //gPad->SetLogz();
   hist7->SetStats(0);
   //hist7->Fit("gaus");
   hist7->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files");
   gStyle->SetPalette(1);

   hist7->Write();
   
   
   Events8->Draw("reco_beam_dEdX_SCE>>hist8(100,0,10","reco_beam_true_byE_PDG==2212");
   
   TH1F * hist8 = (TH1F*)gDirectory->Get("hist8");
   //gStyle->SetPalette(2);
   hist8->SetFillColor(2);
   hist8->SetXTitle ("dE/dX [MeV/cm], sce corr");
   hist8->SetYTitle ("Number of Events");
   //hist8->Fit("gaus");
   hist8->SetTitle("DUNE: ProtoDUNE-HD, p");
   //gStyle->SetPalette(1);

   hist8->Write();
   
   Events9->Draw("reco_beam_dEdX_SCE>>hist9(100,0,10","reco_beam_true_byE_PDG==13");
   
   TH1F * hist9 = (TH1F*)gDirectory->Get("hist9");
   gStyle->SetPalette(3);
   hist9->SetFillColor(3);
   hist9->SetXTitle ("dE/dX [MeV/cm], sce corr");
   hist9->SetYTitle ("Number of Events");
   //hist9->Fit("gaus");
   hist9->SetTitle("DUNE: ProtoDUNE-HD, #mu");
   //gStyle->SetPalette(1);

   hist9->Write();
   
   Events10->Draw("reco_beam_dEdX_SCE>>hist10(100,0,10","reco_beam_true_byE_PDG==211");
   
   TH1F * hist10 = (TH1F*)gDirectory->Get("hist10");
   //gStyle->SetPalette(4);
   hist10->SetFillColor(4);
   hist10->SetXTitle ("reco beam dE/dX SCE [MeV/cm]");
   hist10->SetYTitle ("Number of Events");
   //hist9->Fit("gaus");
   hist10->SetTitle("DUNE: ProtoDUNE-HD, #pi^{+}");
   //gStyle->SetPalette(1);

   hist10->Write();
   
   Events11->Draw("true_beam_endZ>0>>hist11(200,All,All");
   
   TH1F * hist11 = (TH1F*)gDirectory->Get("hist11");
   //gStyle->SetPalette(4);
   //hist11->SetFillColor(4);
   hist11->SetXTitle ("endZ [cm]");
   hist11->SetYTitle ("Number of Events");
   //hist11->Fit("gaus");
   hist11->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files, Z_{end, true} > 0");
   //gStyle->SetPalette(1);

   hist11->Write();
   
   Events12->Draw("reco_beam_endY:reco_beam_endZ>>hist12(1200,0,600,1200,0,600","","COLZ");
   
   TH2F * hist12 = (TH2F*)gDirectory->Get("hist12");
   //gStyle->SetPalette(2);
   //hist2->SetFillColor(4);
   hist12->SetXTitle ("reco beam end Z [cm]");
   hist12->SetYTitle ("reco beam end Y [cm]");
   //gPad->SetLogz();
   hist12->SetStats(0);
   hist12->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files");
   gStyle->SetPalette(1);

   hist12->Write();
   
   Events13->Draw("true_beam_endZ>0 && reco_beam_endZ<0>>hist13(200,All,All");
   
   TH1F * hist13 = (TH1F*)gDirectory->Get("hist13");
   //gStyle->SetPalette(4);
   //hist11->SetFillColor(4);
   hist13->SetXTitle ("endZ [cm]");
   hist13->SetYTitle ("Number of Events");
   //hist13->Fit("gaus");
   hist13->SetTitle("DUNE: ProtoDUNE-HD, 2 GeV prod files, Z_{end, true} > 0");
   //gStyle->SetPalette(1);

   hist13->Write();
   
   Events14->Draw("reco_beam_endZ>>hist14(100,All,All","(true_beam_PDG==abs(211) || true_beam_PDG==abs(2212) || true_beam_PDG==abs(321)) " "");
   TH1F * hist14 = (TH1F*)gDirectory->Get("hist14");
   //gStyle->SetPalette(1);
   hist14->SetXTitle ("endZ [cm]");
   hist14->SetYTitle ("Events");
   hist14->SetTitle("p, #pi^{+}, K^{+}");
   hist14->Write();
   
   Events15->Draw("TMath::ATan2(sqrt(pow(true_beam_daughter_startPx,2)+pow(true_beam_daughter_startPy,2)),true_beam_daughter_startPz):sqrt(pow(true_beam_daughter_startPx,2)+pow(true_beam_daughter_startPx,2)+pow(true_beam_daughter_startPz,2))>>hist15(500,0,5,260,0,1.3","","colz");
   TH2F * hist15 = (TH2F*)gDirectory->Get("hist15");
   //gStyle->SetPalette(1);
   hist15->SetXTitle ("P [GeV/c]");
   hist15->SetYTitle ("#theta [rad]");
   hist15->SetTitle("DUNE: ProtoDUNE-HD, true_beam_daughter");
   hist15->Write();
   
   
                  
}



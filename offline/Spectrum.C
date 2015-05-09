{
  gStyle->SetOptStat(0);
  //gROOT->SetStyle("Plain");

  gStyle->SetLabelSize(0.1,"XYZ");
  cout<<gStyle->GetLabelSize()<<endl;
  gStyle->SetLabelOffset(0.007,"XYZ");
  gStyle->SetTitleSize(0.04,"xyz"); // axis titles
  gStyle->SetTitleOffset(1.0000,"xyz");
  gStyle->SetStripDecimals(kFALSE); // if we have 1.5 do not set 1.0 -> 1
  gStyle->SetLabelColor(2,"xyz");


 

  TFile *fil=new TFile("histos.root");
  TH1F *his=(TH1F*)fil->Get("SeGAtot2");
  his->SetLineColor(kBlue+2);
  TCanvas *c1=new TCanvas("C","",700,972);
  //TCanvas *c1=new TCanvas("C","",700);
  c1->Divide(1,4);
  c1->cd(1)->SetLogy(1);
  c1->cd(1)->SetTopMargin(0);
  c1->cd(1)->SetRightMargin(0.03);
  c1->cd(1)->SetBottomMargin(0.07);
  TH1F *his1=(TH1F*)his->Clone("his1");
  his1->SetTitle("");
  his1->GetXaxis()->SetLabelSize(0.08);
  his1->GetXaxis()->SetNdivisions(5,10,0);
  his1->GetYaxis()->SetLabelSize(0.08);
  his1->GetXaxis()->SetRangeUser(400.,1500.);
  his1->GetYaxis()->SetRangeUser(400,50000);
  his1->Draw();

  //Labelling peaks
  tex = new TLatex(453.,6500,"^{25}Al(451.7)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  
  
  tex = new TLatex(493.,6871.467,"^{25}Al(493.3)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 

  tex = new TLatex(583.306,2002.59,"^{208}Tl(583.2)");
  tex->SetTextColor(1);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 
  tex = new TLatex(609.087,1939.37,"^{214}Bi(609.3)");
  tex->SetTextColor(1);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  
  tex = new TLatex(775,1500.,"^{26}Si**(1797)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(829,5600,"^{26}Al(829)");
  tex->SetTextColor(6);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  
  tex = new TLatex(847.2215,1550.554,"^{25}Al(844.6)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  
  tex = new TLatex(944.2323,1464.327,"^{25}Al(944.9)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  
  tex = new TLatex(972.684,1313.26,"^{26}Si(970.4)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  

  tex = new TLatex(991.462,2632.09,"^{26}Si(988.1)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 


  tex = new TLatex(1066.81,1035.79,"^{26}Si(1071.8)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1076.81,1035.79,"^{24}Mg(1076.8)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  

  tex = new TLatex(1286.06,958.456,"^{26}Si*(1797)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1329.4,1000,"^{26}Si(1329.4)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
      
  tex = new TLatex(1338,1550.554,"^{25}Al(1338)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  
  tex = new TLatex(1351,1000,"^{26}Si(1351)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1368.68,7500.88,"^{24}Mg(1368.6)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(1405.36,1509.03,"^{26}Si(1400.7)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1463.246,1027.659,"^{40}K(1461)");
  tex->SetTextColor(1);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 
  //}

 
  c1->cd(2)->SetLogy(1);
  c1->cd(2)->SetTopMargin(0);
  c1->cd(2)->SetRightMargin(0.03);
  c1->cd(2)->SetBottomMargin(0.08);
  TH1F *his2=(TH1F*)his->Clone("his2");
  his2->SetTitle("");
  his2->GetXaxis()->SetLabelSize(0.08);
  his2->GetXaxis()->SetNdivisions(5,10,0);
  his2->GetYaxis()->SetLabelSize(0.08);
  his2->GetXaxis()->SetRangeUser(1500.,2500.);
  his2->GetYaxis()->SetRangeUser(10,15000);
  his2->Draw();

  //Labelling peaks
  tex = new TLatex(1531.51,715.406,"^{26}Si(1531.1)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1613.887,865.2717,"^{25}Al(1612.4)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1622.3,900,"^{26}Al(1622.3)");
  tex->SetTextColor(6);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1732,350.88,"^{24}Mg**(2754)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1741.74,376.68,"^{26}Si(1742)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1760,376.68,"^{26}Si(1760)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1775,865.2717,"^{25}Al(1775)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1788.311,692.2045,"^{25}Al(1789.4)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(1796.022,12103.85,"^{26}Si(1797)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
      
  tex = new TLatex(1811.216,244.9424,"^{25}Al(1811.6)");
  tex->SetTextColor(4);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(1830,313.85,"^{26}Si*(2341)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(1880,313.85,"^{26}Si*(2391)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(1962.31,498.147,"^{26}Si(1960.4)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2025.12,710.494,"^{26}Si(2024.2)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(2049.6,213.682,"^{26}Si(2044.9)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
      
  tex = new TLatex(2103.06,359,"^{208}Tl*(2614)");
  tex->SetTextColor(1);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2243,500.88,"^{24}Mg(2754)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 
  tex = new TLatex(2276,313.682,"^{26}Si*(2787)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 

  tex = new TLatex(2344.66,848.497,"^{26}Si(2341.9)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2362.94,206.083,"^{26}Si(2360.2)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2393.16,467.666,"^{26}Si(2391.4)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2490,467.666,"^{26}Si*(3001)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();



  c1->cd(3)->SetLogy(1);
  c1->cd(3)->SetTopMargin(0);
  c1->cd(3)->SetBottomMargin(0.08);
  c1->cd(3)->SetRightMargin(0.03);
  TH1F *his3=(TH1F*)his->Clone("his3");
  his3->SetTitle("");
  his3->GetXaxis()->SetNdivisions(5,10,0);
  his3->GetXaxis()->SetLabelSize(0.08);
  his3->GetYaxis()->SetLabelSize(0.08);
  his3->GetXaxis()->SetRangeUser(2500.,4500.);
  his3->GetYaxis()->SetRangeUser(10,4500);
  his3->Draw();


  //Labelling peaks
  tex = new TLatex(2614.355,257.5557,"^{208}Tl(2614.5)");
  tex->SetTextColor(1);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2650.88,318.232,"^{26}Si(2649)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2732.13,131.363,"^{26}Si(2733)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2762.01,1512.35,"^{24}Mg(2754.0)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2786.02,484.443,"^{26}Si(2787.5)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2732.13,131.363,"^{26}Si(2733)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
  

  tex = new TLatex(2876.82,111.755,"^{24}Mg(2869.5)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3001.59,153.534,"^{26}Si(3001.0)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3178,111.755,"^{24}Mg**(4200)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

 tex = new TLatex(3205,300.755,"^{24}Mg**(3203)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3294,161.755,"^{24}Mg**(4316)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3350,131.363,"^{26}Si(3350)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

 tex = new TLatex(3506,200.755,"^{24}Mg**(3506)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3630,153.534,"^{26}Si*(4141)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3689,161.755,"^{24}Mg*(4200)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(3726,161.755,"^{24}Mg*(4237)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  // tex = new TLatex(3769,161.755,"^{24}Mg*(4280)");
  // tex->SetTextColor(3);
  // tex->SetTextAlign(12);
  // tex->SetTextSize(0.05);
  // tex->SetTextFont(42);
  // tex->SetTextAngle(90);
  // tex->SetLineWidth(2);
  // tex->Draw();

  tex = new TLatex(3805,181.755,"^{24}Mg*(4316)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();


  tex = new TLatex(3866,167.813,"^{24}Mg(3866.19)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4140.274,106.3748,"^{26}Si(4141)");
  tex->SetTextColor(2);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4200,201.755,"^{24}Mg(4200");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4242.24,128.452,"^{24}Mg(4237.96)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4280.6,128.452,"^{24}Mg(4280.6)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4316.66,295.795,"^{24}Mg(4316.0)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(4370.66,145.795,"^{24}Mg**(5392)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  c1->cd(4)->SetLogy(1);
  c1->cd(4)->SetTopMargin(0);
  c1->cd(4)->SetBottomMargin(0.08);
  c1->cd(4)->SetRightMargin(0.03);
  TH1F *his4=(TH1F*)his->Clone("his4");
  his4->SetTitle("");
  his4->GetXaxis()->SetNdivisions(5,10,0);
  his4->GetXaxis()->SetTitle("");
  his4->GetXaxis()->SetLabelSize(0.08);
  his4->GetYaxis()->SetLabelSize(0.08);
  his4->GetXaxis()->SetRangeUser(400.,1500.);
  his4->GetYaxis()->SetRangeUser(100,20000);
  his4->GetXaxis()->SetRangeUser(4500.,7500.);
  his4->GetYaxis()->SetRangeUser(8,2500);
  his4->Draw();

  //Labelling peaks
  tex = new TLatex(4644.87,101.594,"^{24}Mg(4641.16)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();
 
  tex = new TLatex(4880,101.594,"^{24}Mg*(5392)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(5392,201.594,"^{24}Mg(5392)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(6045,101.594,"^{24}Mg**(7067)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(6556,301.594,"^{24}Mg*(7067)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(7067,301.594,"^{24}Mg(7067.4)");
  tex->SetTextColor(3);
  tex->SetTextAlign(12);
  tex->SetTextSize(0.05);
  tex->SetTextFont(42);
  tex->SetTextAngle(90);
  tex->SetLineWidth(2);
  tex->Draw();








}

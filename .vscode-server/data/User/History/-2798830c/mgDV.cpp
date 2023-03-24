#include #include <TGraphErrors.h> #include <TFile.h> #include <TH1F.h>

void create_TGraphErrors() { // open the root file 
TFile *f = new TFile("myfile.root", "READ");

// get the x, y, and error data 
TH1F h_x = (TH1F)f->Get("h_x"); 
TH1F h_y = (TH1F)f->Get("h_y"); 
TH1F h_err = (TH1F)f->Get("h_err");

// create arrays to hold the x, y and error values 
int nbins = h_x->GetNbinsX();
 double x[nbins], y[nbins], err[nbins]; 
 for (int i=0; i<nbins; i++) { 
    x[i] = h_x->GetBinContent(i); 
    y[i] = h_y->GetBinContent(i); 
    err[i] = h_err->GetBinContent(i); 
    }


// create the TGraphErrors 
TGraphErrors *g = new TGraphErrors(nbins,x,y,0,err);

// format and draw the TGraphErrors 
g->SetMarkerStyle(20); 
g->SetMarkerSize(2); 
g->Draw("AP");

}




//PI VALUE


#include <stdio.h> #include <stdlib.h> #include <time.h>

int main(){
     srand(time(0)); 
     int inside_count = 0; 
     int total_count = 0; 
     while(total_count < 1000000){ 
        double x = ((double) rand() / (RAND_MAX)); 
        double y = ((double) rand() / (RAND_MAX));
         double dist = (xx) + (yy); 
         if(dist <= 1){ 
            inside_count++; 
            } 
            total_count++; 
            }

float pi_value = 4.0 * ((float)inside_count / (float)total_count);
printf("%f\n",pi_value);
return 0;
}
ile(sum<(1-CL)){
sum=0.;
	for(r=0;r<N;r++){
	sum+=TMath::Poisson(r,lambda);
	}

	lambda-=0.001;

}

return lambda+0.001

}


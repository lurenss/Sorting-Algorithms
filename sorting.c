#include <stdio.h>

void bubble(int v[], int d){
	int temp,i,j;
	for(i=d-1;i>0;i--){
		for(j=d-1;j>0;j--){
			if(v[j-1]>v[j]){
				temp=v[j-1];
				v[j-1] = v[j];
				v[j] = temp;
			}
		}
	}
}

void bubbleric(int v[],int i, int d){
	int temp;
	if(d==0 || i==d){
		return;
	}

	if(v[i]>v[i+1]){
			temp=v[i+1];	
			v[i+1] = v[i];
			v[i] = temp;
			bubbleric(v,i+1,d);
			bubbleric(v,i,d-1);
	}		
		bubbleric(v,i+1,d);
		bubbleric(v,i,d-1);
}

void insertions(int a[],int d){
	int i,j,supp;
	for(i=1;i<d;i++){
		supp=a[i];
		j=i-1;
		while(j>=0 && a[j]>supp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=supp;
	}
}

void insric(int a[],int d){
	int supp;
	int j;
	if(d==1){
		return;
	}
	else{
		insric(a,d-1);
		supp=a[d-1];
		j=d-2;
		while(a[j]>supp && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=supp;
	}
}

void sel(int a[], int d){
	int i,j,supp,aux,scambia;
	aux=0;
	for(i=0;i<d;i++){
		supp=a[i];
		for(j=i+1;j<d;j++){
			if(a[j]<supp){
				supp=a[j];
				aux=j;
			}
		}
		if(supp!=a[i]){
			scambia=a[i];
			a[i]=supp;
			a[aux]=scambia;
		}	
	}
}

void selric(int a[],int i,int d){
	int supp;
	if(d==0 || i==d){
		return;
	}
	supp=a[i];
	if(supp>a[d]){
		a[i]=a[d];
		a[d]=supp;
	}
	selric(a,i+1,d);
	selric(a,i,d-1);
}

int main(){
	int i;
	int v[3] = {1,2,3};
	int d = sizeof(v)/sizeof(v[0]);
	for(i=0;i<=d;i++){
		printf("%d,",v[i]);
	}
	printf("\n");
	printf("%d\n",d);
	selric(v,0,d-1);
	for(i=0;i<d;i++){
		printf("%d,",v[i]);
	}
	printf("\n");
	return 0;
}

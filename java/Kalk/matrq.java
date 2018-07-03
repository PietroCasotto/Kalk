package Kalk;

public class matrq extends matrice {

	/** Costruttore di copia*/
	public matrq(matrq m) {
		this(m.getC(),m.getDati());
	}

	/** Costruttore*/
	public matrq(int r, double[] v) {
		super(r, r, v);
	}

	/** Costruttore ad un parametro*/
	public matrq(int r) {
		super(r, r);
	}

	/** Costruttore senza parametri*/
	public matrq() {
		super(0, 0);
	}
	
	/** Funzione che calcola la trasposta*/
	public matrq trasposta() {
	    matrq tmp=new matrq(getR());
	    for(int i=0; i<this.getR(); ++i){
	        for(int j=0; j<this.getR(); ++j){
	            (tmp.getDati())[i+j*this.getR()]=(this.getDati())[j+i*this.getR()];
	        }
	    }
	    return tmp;
	}
	
	/** Funzione che calcola il determinante
	 * throws ErrCalcolo*/
	public scalare determinante() throws ErrCalcolo {
	    int n=getC();
	    double det=1;
	    double[] L, A;
	    L=new double[n*n];
	    A=new double[n*n];
	    for(int i=0; i<n*n; ++i){
	        A[i]=getDati()[i];
	        L[i]=0;
	    }
	    for (int i=0; i<getC(); i++){
	        L[i+n*i]=1;
	    }
	    for(int k=0; k<(n-1); k++){
	        for(int i=k+1;i<n; i++){
	        	if (A[k+n*k]==0) {
    	    		throw new ErrCalcolo("Divisione per zero");
	        	}
	            L[i+n*k]=A[i+n*k]/A[k+n*k];
	            for(int j=k; j<n; j++){
	                A[i+n*j]=A[i+n*j]-L[i+n*k]*A[k+n*j];
	            }
	        }
	    }
	    for(int i=0; i<n; i++){
	        det=det*A[i+n*i];
	    }
		scalare v=new scalare(det);
		return v;
	}
	
	/** Funzione che calcola l'inversa
	 * throws ErrCalcolo*/
	public matrq inversa() throws ErrCalcolo{
		int n = getC(), dim=getR()*getC();
		scalare d=new scalare(0);
		double[] A=new double[dim], B=new double[dim];
		double p, y;
		for(int i=0;i<dim;++i){
				A[i]=getDati()[i];
		}
		try {
			d=determinante();
		}
		catch (ErrCalcolo ec) {
			return this;
		}
		if(d.equals(0)){
			throw new ErrCalcolo("Determinate unguale a zero, calcolo non possibile");
		}
			for(int i=0;i<n;++i){
					for(int j=0;j<n;++j){
							if(i==j){
									B[i*n+j]=1;
							}
							else{
									B[i*n+j]=0;
							}
					}
			}

			for(int k=0; k<n; ++k){
					p=A[k*n+k];
					if(p==0) {
						throw new ErrCalcolo("Divisione per zero");
					}
					for(int j=0;j<n;++j){
							A[k*n+j]=A[k*n+j]/p;
							B[k*n+j]=B[k*n+j]/p;
							}
					for(int i=0;i<n; ++i){
							if(i!=k){
									y=A[i*n+k];
									for(int j=0; j<n;++j){
											A[i*n+j]=A[i*n+j]-A[k*n+j]*y;
											if(A[i*n+j]<(1e-009) && A[i*n+j]>(-1e-009)){
													A[i*n+j]=0;
											}
											B[i*n+j]=B[i*n+j]-B[k*n+j]*y;
											if(B[i*n+j]<(1e-009) && B[i*n+j]>(-1e-009)){
													B[i*n+j]=0;
											}
									}
							}
					}
			}

		return new matrq(n, B);
	}

}

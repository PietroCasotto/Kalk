package Kalk;

public class matrice implements operando {
	
	private int n_riga;
	private int el_riga;
	private double[] dati;

	/** Funzione di accesso ai dati*/
	public double[] getDati(){
		return dati;
	}

	/** Funzione di modifica dei dati*/
	public void setDati(double[] d) {
		dati=d;
	}

	/** Funzione che ritorna il numero delle righe della matrice*/
	public int getR() {
		return el_riga;
	}

	/** Funzione che ritorna il numero delle colonne della matrice*/
	public int getC() {
		return n_riga;
	}

	/** Funzione che modifica il numero delle righe della matrice*/
	public void setR(int r) {
		el_riga=r;
	}

	/** Funzione che modifica il numero delle colonne della matrice*/
	public void setC(int c) {
		n_riga=c;
	}

	/** Costruttore di copia*/
	public matrice(matrice m){
		el_riga=m.el_riga;
		n_riga=m.n_riga;
		dati= new double[el_riga*n_riga];
		for(int i=0; i<el_riga*n_riga; ++i) {
			dati[i]=m.dati[i];
		}
	}

	/** Costruttore*/
	public matrice(int r, int c, double[] v){
		el_riga=r;
		n_riga=c;
		dati= new double[r*c];
		for(int i=0; i<r*c; ++i) {
			dati[i]=v[i];
		}
	}

	/** Costruttore ad due parametri*/
	public matrice(int r, int c){
		this(r, c, new double[r*c]);
		for (int i=0; i<r*c; i++) {
			dati[i]=0.0;
		}
	}

	/** Costruttore senza parametri*/
	public matrice(){
		this(0,0);
	}

	
	/** Funzione che effettua la moltiplicazione
	 * throws ErrCalcolo*/
	@Override
	public operando moltiplicazione(operando pro) throws ErrCalcolo{
		    double[] t=new double[this.el_riga*this.n_riga];
			if(pro instanceof scalare){
		    	scalare s=(scalare)pro;
		        for(int i=0; i<getR()*getC(); ++i){
		            t[i]=dati[i]*s.get_val();
		        }
		    }
		    if(pro instanceof matrice) {
		    	throw new ErrCalcolo("Funzione non implementata");
		    }
			if (this instanceof matrq) {
				return new matrq(el_riga, t);
			}
		    return new matrice(el_riga, n_riga, t);
	}

	/** Funzione che effettua la somma
	 * throws ErrCalcolo*/
	@Override
	public operando somma(operando sum) throws ErrCalcolo {
	    double[] t=new double[this.el_riga*this.n_riga];
	    for(int i=0; i<getR()*getC(); ++i) {
	    	t[i]=dati[i];
	    }
		if(sum instanceof scalare){
	    	scalare s=(scalare)sum;
	        for(int i=0; i<getR()*getC(); ++i){
	            t[i]=dati[i]+s.get_val();
	        }
	    }
	    else if(sum instanceof matrice){
	    	matrice m=(matrice)sum;
	    	if((getR()==m.getR())&&(getC()==m.getC())){
		        for(int i=0; i<getR()*getC(); ++i){
		            t[i]=dati[i]+m.getDati()[i];
		        }
	    	}
	    	else {
	    		throw new ErrCalcolo("Dimensioni delle matrici non compatibili");
	    	}
	    }
		if (this instanceof matrq) {
			return new matrq(el_riga, t);
		}
	    return new matrice(el_riga, n_riga, t);
	}

	/** Funzione che effettua la sottrazione
	 * throws ErrCalcolo*/
	@Override
	public operando sottrazione(operando sot) throws ErrCalcolo {
	    double[] t=new double[this.el_riga*this.n_riga];
	    for(int i=0; i<getR()*getC(); ++i) {
	    	t[i]=dati[i];
	    }
		if(sot instanceof scalare){
	    	scalare s=(scalare)sot;
	        for(int i=0; i<getR()*getC(); ++i){
	            t[i]=dati[i]-s.get_val();
	        }
	    }
	    else if(sot instanceof matrice){
	    	matrice m=(matrice)sot;
	    	if((getR()==m.getR())&&(getC()==m.getC())){
		        for(int i=0; i<getR()*getC(); ++i){
		            t[i]=dati[i]-m.getDati()[i];
		        }
	    	}
	    	else {
	    		throw new ErrCalcolo("Dimensioni delle matrici non compatibili");
	    	}
	    }
		if (this instanceof matrq) {
			return new matrq(el_riga, t);
		}
	    return new matrice(el_riga, n_riga, t);
	}
	
	/** Funzione che calcola la trasposta*/
	public matrice trasposta(){
	    matrice tmp=new matrice(n_riga, el_riga);
	    for(int i=0; i<n_riga; ++i){
	        for(int j=0; j<el_riga; ++j){
	            (tmp.getDati())[i+j*n_riga]=dati[j+i*el_riga];
	        }
	    }
	    return tmp;
	}
	
	/** Overload del metodo toString*/
	public String toString() {
	    String buff="";
	    buff+="{ ";
	    for (int j=0; j<getC(); ++j){
	        for(int i=0; i<getR(); ++i){
	            buff+=(dati[i+j*el_riga]);
	            if(i<(getR()-1)){
	                buff+=" ";
	            }
	        }
	        if(j<(getC()-1)){
	            buff+=" $ ";
	        }
	    }
	    buff+=" }";
	    return buff;
	}

}

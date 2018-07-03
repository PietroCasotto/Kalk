package Kalk;


public class pcompl implements operando {
	

	private double reale;
	private double immaginaria;
	
	/** Costruttore*/
	public pcompl(double r, double i){
		reale=r;
		immaginaria=i;
	}
	
	/** Costruttore ad un parametro*/
	public pcompl(double r){
		this(r, 0);
	}
	
	/** Costruttore senza parametri*/
	public pcompl(){
		this(0,0);
	}
	
	/** Costruttore di copia*/
	public pcompl(pcompl c){
		reale=c.reale;
		immaginaria=c.immaginaria;
	}
	
	/** Funzione che modifica la parte reale della matrice*/
	public void set_reale(double r) {
		reale=r;
	}
	
	/** Funzione che modifica la parte immaginaria della matrice*/
	public void set_imm(double i) {
		immaginaria=i;
	}
	
	/** Funzione che ritorna la parte reale della matrice*/
	public double get_reale() {
		return reale;
	}
	
	/** Funzione che ritorna la parte immaginaria della matrice*/
	public double get_immaginaria() {
		return immaginaria;
	}

	/** Funzione che effettua la moltiplicazione
	 * throws ErrCalcolo*/
	@Override
	public operando moltiplicazione(operando pro) throws ErrCalcolo {
		double rfi=reale, ifi=immaginaria;
		if(pro instanceof pcompl) {
			pcompl c=(pcompl)pro;
	        double r1=reale, i1=immaginaria;
	        double r2=c.get_reale(), i2=c.get_immaginaria();
	        rfi=(r1*r2)-(i1*i2);
	        ifi=(r1*i2)+(i1*r2); 
		}
		else if(pro instanceof scalare) {
			scalare s=(scalare)pro;
			rfi=reale*s.get_val();
	        ifi=immaginaria*s.get_val();
		}
		return new pcompl(rfi, ifi);
	}

	/** Funzione che effettua la somma
	 * throws ErrCalcolo*/
	@Override
	public operando somma(operando sum) throws ErrCalcolo {
		double rfi=reale, ifi=immaginaria;
		if(sum instanceof pcompl) {
			pcompl c=(pcompl)sum;
			rfi=reale+c.get_reale();
			ifi=immaginaria+c.get_immaginaria();
		}
		else if(sum instanceof scalare) {
			scalare s=(scalare)sum;
			rfi=reale+s.get_val();
		}
		return new pcompl(rfi, ifi);
	}

	/** Funzione che effettua la sottrazione
	 * throws ErrCalcolo*/
	@Override
	public operando sottrazione(operando sot) throws ErrCalcolo {
		double rfi=reale, ifi=immaginaria;
		if(sot instanceof pcompl) {
			pcompl c=(pcompl)sot;
	        rfi=reale-c.get_reale();
	        ifi=immaginaria-c.get_immaginaria();
		}
		else if(sot instanceof scalare) {
			scalare s=(scalare)sot;
			rfi=reale-s.get_val();
		}
		return new pcompl(rfi, ifi);
	}
	
	/** Funzione che calcola il coniugato*/
	public pcompl coniugato() {
		double i=immaginaria;
	    i= immaginaria*(-1);
	    return new pcompl(reale, i);
	}
	
	/** Funzione che calcola il modulo*/
	public scalare modulo() {
	    double c=reale*reale+immaginaria*immaginaria;
	    return new scalare(Math.sqrt(c));
	}
	
	/** Funzione che calcola la potenza 2*/
	public pcompl potenza() {
	    double n_r=reale, n_i=immaginaria;
	    reale=(n_r*n_r)-(n_i*n_i);
	    immaginaria=(n_r*n_i)+(n_i*n_r);
	    return this;
	}
	
	/** Overload del metodo toString*/
	public String toString() {
		if (immaginaria >=0) {
			return "( "+reale+" +i "+immaginaria+" )";
		}
		else {
			double s=immaginaria*(-1);
			return "( "+reale+" -i "+s+" )";
		}
	}

}

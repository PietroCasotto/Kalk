package Kalk;

public class scalare implements operando {
	
	private double reale;
	
	/** Costruttore ad un parametro*/
	public scalare(double r){
		this.reale=r;
	}

	/** Costruttore senza parametri*/	
	public scalare(){
		this(0);
	}

		/** Costruttore di copia*/
	public scalare (scalare s){
		this.reale=s.reale;
	}

	/** Funzione che effettua la moltiplicazione
	 * throws ErrCalcolo*/
	@Override
	public operando moltiplicazione(operando pro) throws ErrCalcolo {
		if(pro instanceof scalare) {
			scalare s=(scalare)pro;
			this.reale=this.reale*s.reale;
		}
		else {
    		return pro.moltiplicazione(this);
    	}
		return this;
	}

	/** Funzione che effettua la somma
	 * throws ErrCalcolo*/
	@Override
	public operando somma(operando sum) throws ErrCalcolo {
		if(sum instanceof scalare) {
			scalare s=(scalare)sum;
			this.reale=this.reale+s.reale;
		}
		else {
    		return sum.somma(this);
    	}
		return this;
	}

	/** Funzione che effettua la sottrazione
	 * throws ErrCalcolo*/
	@Override
	public operando sottrazione(operando sot) throws ErrCalcolo {
		if(sot instanceof scalare) {
			scalare s=(scalare)sot;
			this.reale=this.reale-s.reale;
		}
		else {
    		return sot.sottrazione(this);
    	}
		return this;
	}

	/** Funzione di accesso al valore*/
	public double get_val() {
		return reale;
	}

	/** Funzione che confronta lo scalare con un double*/
	public boolean equals(double eq) {
		return eq==reale;
	}

	/** Overload del metodo toString()*/
	public String toString() {
		return reale+" ";
	}
}

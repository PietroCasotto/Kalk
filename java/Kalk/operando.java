package Kalk;

public interface operando{

	/** Funzione che effettua la moltiplicazione
	 * throws ErrCalcolo*/
	operando moltiplicazione(operando pro) throws ErrCalcolo;
	/** Funzione che effettua la somma
	 * throws ErrCalcolo*/
	operando somma(operando sum) throws ErrCalcolo;
	/** Funzione che effettua la sottrazione
	 * throws ErrCalcolo*/
	operando sottrazione(operando sot) throws ErrCalcolo;
	
}

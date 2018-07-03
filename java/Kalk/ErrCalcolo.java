package Kalk;

public class ErrCalcolo extends Exception {
	
	public ErrCalcolo(String reason) {
		super(reason); 
	}
	
	public String getReason() { 
		return this.getMessage(); 
	}
	private static final long serialVersionUID = 1129997115L;

}

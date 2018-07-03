
import Kalk.*;

public class Use {

	public static void main(String[] args) {
		operando o1, o2, o3;
		scalare s1= new scalare(4);
		System.out.println("s1  "+s1);
		pcompl c1=new pcompl (3, 2);
		System.out.println("c1  "+c1);
		pcompl c2=new pcompl(4, -5);
		System.out.println("c2  "+c2);
		double[] a1= new double[6];

		a1[0]=9;
		a1[1]=4;
		a1[2]=1;
		a1[3]=6;
		a1[4]=8;
		a1[5]=6;
		double[] a2= new double[6];

		a2[0]=1;
		a2[1]=10;
		a2[2]=2;
		a2[3]=3;
		a2[4]=1;
		a2[5]=7;
		matrice m1=new matrice(2, 3, a1);
		System.out.println("m1  "+m1);
		matrice m2=new matrice(2, 3, a2);
		System.out.println("m2  "+m2);
		matrq mq1=new matrq(2, a1);
		System.out.println("mq1 "+mq1);
		matrq mq2=new matrq(2, a2);
		System.out.println("mq2 "+mq2);
		System.out.println("\n");
		
		o1=c1;
		o2=c2;
		try {
			o3=o1.somma(o2);
			System.out.println("c1+c2 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1+c2 "+ec.getReason());
		}		
		try {
			o3=o1.sottrazione(o2);
			System.out.println("c1-c2 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1-c2 "+ec.getReason());
		}		
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("c1*c2 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1*c2 "+ec.getReason());
		}		
		o2=s1;
		try {
			o3=o1.somma(o2);
			System.out.println("c1+s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1+s1 "+ec.getReason());
		}		
		try {
			o3=o1.sottrazione(o2);
			System.out.println("c1-s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1-s1 "+ec.getReason());
		}		
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("c1*s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("c1*s1 "+ec.getReason());
		}		
		o3=c1.coniugato();
		System.out.println("coniugato di c1 "+o3);
		o3=c1.modulo();
		System.out.println("modulo di c1 "+o3);	
		o3=c1.potenza();
		System.out.println("potenza di c1 "+o3);
		
		o1=m1;
		o2=m2;
		try {
			o3=o1.somma(o2);
			System.out.println("m1+m2 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("m1+m2 "+ec.getReason());
		}	
		try {
			o3=o1.sottrazione(o2);
			System.out.println("m1-m2 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("m1-m2 "+ec.getReason());
		}	
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("m1*m2 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("m1*m2 "+ec.getReason());
		}		
		o2=s1;
		try {
			o3=o1.somma(o2);
			System.out.println("m1+s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("m1+s1 "+ec.getReason());
		}		
		try {
			o3=o1.sottrazione(o2);
			System.out.println("m1-s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("m1-s1 "+ec.getReason());
		}		
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("m1*s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("m1*s1 "+ec.getReason());
		}
		o3=m1.trasposta();
		System.out.println("trasposta di m1 "+o3);
		
		o1=mq1;
		o2=mq2;
		try {
			o3=o1.somma(o2);
			System.out.println("mq1+mq2 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1+mq2 "+ec.getReason());
		}	
		try {
			o3=o1.sottrazione(o2);
			System.out.println("mq1-mq2 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1-mq2 "+ec.getReason());
		}	
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("mq1*mq2 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1*mq2 "+ec.getReason());
		}	
		o2=s1;
		try {
			o3=o1.somma(o2);
			System.out.println("mq1+s1 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1+s1 "+ec.getReason());
		}	
		try {
			o3=o1.sottrazione(o2);
			System.out.println("mq1-s1 "+o3);	
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1-s1 "+ec.getReason());
		}	
		try {
			o3=o1.moltiplicazione(o2);
			System.out.println("mq1*s1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("mq1*s1 "+ec.getReason());
		}
		o3=mq1.trasposta();
		System.out.println("trasposta di mq1 "+o3);
		try {
			o3=mq1.determinante();
			System.out.println("determinante di mq1 "+o3);
		}
		catch (ErrCalcolo ec){
			System.out.println("determinante di mq1 "+ec.getReason());
		}
		try {
			o3=mq1.inversa();
			System.out.println("inversa di mq1 "+o3);
			}
			catch (ErrCalcolo ec){
				System.out.println("inversa di mq1 "+ec.getReason());
			}

		}

	}

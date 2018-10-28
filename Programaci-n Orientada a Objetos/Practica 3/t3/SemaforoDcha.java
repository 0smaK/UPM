package t3;

public class SemaforoDcha extends Semaforo implements ISemaforoDcha {

	private int colorDcha;

	public SemaforoDcha() {
		setColorDerecha(ROJO);
	}

	public SemaforoDcha(int colorDcha) {
		this.colorDcha = colorDcha;
	}

	public SemaforoDcha(int colorCentral, int colorDcha) {
		super(colorCentral);
		setColorDerecha(colorDcha);
	}

	public int getColorDcha() {
		return colorDcha;
	}

	public void setColorDerecha(int colorDcha) {
		this.colorDcha = colorDcha;
	}

	public boolean equals(ISemaforoDcha s) {
		return super.equals(s) && colorDcha == s.getColorDcha();
	}

	public ISemaforoDcha clone() {
		return new SemaforoDcha(getColorCentral(), getColorDcha());
	}

	public String toString() {
		return super.toString() + " ,Dcha: " + colorDcha; // Redefinición
	}

}
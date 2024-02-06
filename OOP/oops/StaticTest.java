public class StaticTest {
    
    static int a = 20;

    void m1() {
        int a = 30;
        System.out.println("a: " + a);
        System.out.println("b: " + StaticTest.a); 
    }

    public static void main(String[] args) {
        StaticTest st = new StaticTest();
        st.m1();
    }
}

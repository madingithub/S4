package MyPackage;
public class Compare{
    int num1,num2;
    Compare(int n,int m){
        num1=n;
        num2=m;
    }
    public void getmax(){
        if(num1>num2){
            System.out.println("Maximum Value of Two Numbers is:"+num1);
        }else{
            System.out.println("Maximum Value of Two Numbers is:"+num2);
        }
    }
    public static void main(String args[]){
        Compare current[]=new Compare[3];
        current[0]=new Compare(5,10);
        current[1]=new Compare(123,120);
        current[2]=new Compare(8,4);
        for (int i=0;i<3;i++){
            current[i].getmax();
        }
    }
}
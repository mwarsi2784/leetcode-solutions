public class Solution {
    public bool ReorderedPowerOf2(int n) {
        string s=n.ToString();
        char[] charN = s.ToCharArray();
        Array.Sort(charN);
        s=new string(charN);
        for( ulong i=1;i<100000000000000;i=i*2){
            string x = i.ToString();
            char[] charX = x.ToCharArray();
            Array.Sort(charX);
            x = new string(charX);
            if(x==s){
                return true;
            }
        }
        return false;
    }
}
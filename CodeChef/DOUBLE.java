import java.io.*;

class Double
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t, n;

        t = parseInt(br.readLine());

        while (t-- != 0)
        {
            n = parseInt(br.readLine());

            if ((n & 1) != 0)
                out.println(n - 1);
            else
                out.println(n);
        }
        out.flush();
    }

    private static int parseInt(String s)
    {
        int result = 0;
        int i, l = s.length();
        for (i = 0; i < l; i++)
        {
            result *= 10;
            result += s.charAt(i) - 48;
        }
        return result;
    }
}


import java.io.*;

class Panstack
{

    static int[][] bell = new int[1005][1005];

    static void precompute()
    {
        int i, j;

        bell[0][0] = 1;
        for (i = 1; i <= 1001; i++)
        {
            bell[i][0] = bell[i - 1][i - 1];
            for (j = 1; j < i + 1; j++)
                bell[i][j] = (bell[i][j - 1] + bell[i - 1][j - 1]) % 1000000007;
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t, n;

        precompute();

        t = parseInt(br.readLine());
        while (t-- != 0)
        {
            n = parseInt(br.readLine());
            out.println(bell[n][0]);
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

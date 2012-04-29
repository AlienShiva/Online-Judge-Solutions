import java.io.*;
import java.util.StringTokenizer;

class Playfit
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int i, t, n, max_diff, max_after, diff;
        int gi[] = new int[100001];

        t = parseInt(br.readLine());

        while (t-- != 0)
        {
            n = parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (i = 0; i < n; i++)
                gi[i] = parseInt(st.nextToken());

            max_after = max_diff = 0;
            for (i = n - 2; i >= 0; i--)
            {
                if (gi[i + 1] > max_after)
                    max_after = gi[i + 1];

                diff = max_after - gi[i];

                if (diff > max_diff)
                    max_diff = diff;
            }

            if (max_diff > 0)
                out.println(max_diff);
            else
                out.println("UNFIT");
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

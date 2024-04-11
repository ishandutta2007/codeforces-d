
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by Administrator on 2018/1/29.
 */
public class CF920C {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            //   System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\916E.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }


    public static void solve() {
        int n = input.nextInteger();
        int[] data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = input.nextInteger();
        }

        char[] swapable = new char[n];
        input.nextBlock(swapable, 0);
        swapable[n - 1] = '0';

        boolean result = true;
        int lastmin = Integer.MIN_VALUE;
        int lastmax = Integer.MIN_VALUE;
        int curmin = Integer.MAX_VALUE;
        int curmax = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            curmax = Math.max(data[i], curmax);
            curmin = Math.min(data[i], curmin);


            if (swapable[i] == '0') {
                if (curmin < lastmax) {
                    result = false;
                    break;
                }
                lastmax = curmax;
                lastmin = curmin;
                curmax = Integer.MIN_VALUE;
                curmin = Integer.MAX_VALUE;
            }
        }

        System.out.println(result ? "YES" : "NO");
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 4096);
        }

        public BlockReader(InputStream is, int bufSize) {
            this.is = is;
            dBuf = new byte[bufSize];
            next = nextByte();
        }

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
        }

        public String nextBlock() {
            builder.setLength(0);
            skipBlank();
            while (next != EOF && !Character.isWhitespace(next)) {
                builder.append((char) next);
                next = nextByte();
            }
            return builder.toString();
        }

        public int nextInteger() {
            skipBlank();
            int ret = 0;
            boolean rev = false;
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = nextByte();
            }
            while (next >= '0' && next <= '9') {
                ret = (ret << 3) + (ret << 1) + next - '0';
                next = nextByte();
            }
            return rev ? -ret : ret;
        }

        public int nextBlock(char[] data, int offset) {
            skipBlank();
            int index = offset;
            int bound = data.length;
            while (next != EOF && index < bound && !Character.isWhitespace(next)) {
                data[index++] = (char) next;
                next = nextByte();
            }
            return index - offset;
        }

        public boolean hasMore() {
            skipBlank();
            return next != EOF;
        }

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return dBuf[dPos++];
        }
    }
}
import java.math.BigInteger;
import java.security.MessageDigest;

public class Hash {
    public static void main(String[] args) {
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            byte[] bytes = args[0].getBytes();
            messageDigest.update(bytes);
            String str = new BigInteger(1, messageDigest.digest()).toString(36);
            System.out.println(str);
        } catch (Exception e) {
            throw new RuntimeException("Could not hash input string.", e);
        }
    }
}

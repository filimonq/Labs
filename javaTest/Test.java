import javax.sound.sampled.*;

public class Test {
    public static void main(String[] args) {
        try {
            AudioFormat format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 44100, 16, 2, 4, 44100, false);
            DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);
            SourceDataLine line = (SourceDataLine) AudioSystem.getLine(info);
            line.open(format);
            line.start();

            int frequency = 440;  // Частота синусоиды (440 Гц - нота ля)
            byte[] buf = new byte[44100 * 2];
            for (int i = 0; i < buf.length; i += 2) {
                double angle = i / (44100.0 / frequency) * 2.0 * Math.PI;
                short sample = (short) (Math.sin(angle) * 32767);
                buf[i] = (byte) (sample & 0xFF);
                buf[i + 1] = (byte) ((sample >> 8) & 0xFF);
            }

            line.write(buf, 0, buf.length);
            line.drain();
            line.close();
        } catch (LineUnavailableException e) {
            e.printStackTrace();
        }
    }
}

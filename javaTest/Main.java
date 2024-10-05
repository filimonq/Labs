import java.io.ByteArrayInputStream;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class Main {
    public static void main(String[] args) {
        int sampleFrequency = 44100; 
        int sinusoidaFrequency = 440;
        
        byte[] buffer = new byte[sampleFrequency * 2]; // на 2 умножаем, тк 16 бит в одном сэмпле
        
        for (int i = 0; i < buffer.length; i += 2) {
            double angle = 2.0 * Math.PI * i / (sampleFrequency / sinusoidaFrequency);
            short sample = (short) (Math.sin(angle) * Short.MAX_VALUE);
            buffer[i] = (byte) (sample & 0xFF); // извлекает младшие 8 бит
            buffer[i + 1] = (byte) ((sample >> 8) & 0xFF); // старшие 8 бит
        }

        try {
            AudioFormat format = new AudioFormat(sampleFrequency, 16, 1, true, false);
            AudioInputStream audioInputStream = new AudioInputStream(
                    new ByteArrayInputStream(buffer), format, buffer.length / format.getFrameSize());
                    // создание входного потока из массива buffer с аудио данными
            try (
                Clip clip = AudioSystem.getClip()) {
                clip.open(audioInputStream); // запуск воспроизведения звука.
                clip.start(); 
                Thread.sleep(500);
            } 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}



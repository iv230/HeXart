import processing.serial.*;

PrintWriter output;
Serial udSerial;
String data;

void setup() {
  udSerial = new Serial(this, Serial.list()[2], 9600);
  printArray(Serial.list());
  output = createWriter ("Battements.csv");
  output.println("timestamp;pulse");
}

void draw() {
  if (udSerial.available() > 0) {
    data = udSerial.readString();

    if (data.charAt(data.length() - 1) == '_')
    {
        String dataLines[] = data.split("_");

      if (!dataLines[0].contains("null"))
      {
        output.println(dataLines[0]);
      }
      data = "";
    }
  }
}

void keyPressed() {
  output.flush();
  output.close();
  exit();
}

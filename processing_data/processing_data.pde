//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;

//declare
PrintWriter output;
Serial udSerial;
String data;

ArrayList<Integer> xList = new ArrayList<Integer>();
ArrayList<Integer> yList = new ArrayList<Integer>();

final int windowW = 1440;
final int windowH = 900;

void setup() {
  udSerial = new Serial(this, Serial.list()[2], 9600);
  printArray(Serial.list());
  output = createWriter ("Battements.csv");
  output.println("timestamp,pulse");

  size(1440, 900);
  smooth();
}

void draw() {
  if (udSerial.available() > 0) {
    data = data + udSerial.readString();

    if (data.charAt(data.length() - 1) == '_')
    {
      String dataLines[] = data.split("_");

      if (!dataLines[0].contains("null"))
      {
        output.println(dataLines[0]);
        String datas[] = data.split(",");

        StringBuilder sb = new StringBuilder(datas[1]);
        sb.deleteCharAt(sb.length() - 1);
        datas[1] = sb.toString();

        xList.add(
          parseInt(datas[0])
        );
        yList.add(
          parseInt(datas[1])
        );

        background(40);

        for (
          int i = xList.size() >= 2000 ? xList.size() - 2000 : 0; 
          i < xList.size(); 
          i++
          )
        {

          int x = (int) map(
            xList.get(i), 
            0, 
            2000, 
            0, 
            windowW
           );
          
          int y = (int) map(
            yList.get(i), 
            0, 
            200, 
            0, 
            windowH
           );
            
          stroke(255);
          line(100 * i, windowH, 100 * (i + 1), windowH - y);
          //rectMode(CORNER);
          //rect(x, windowH-100, 1, y);
        }
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

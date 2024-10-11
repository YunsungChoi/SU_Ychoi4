package stubs;
import java.io.IOException;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper; 


public class TFIDFMapper3 extends Mapper<LongWritable, Text , Text, Text>{
	@Override
	public void map(LongWritable key, Text value, Context context) 
		throws IOException, InterruptedException{
			String[] inputs = value.toString().split("\t"); 
			if (inputs.length == 2) {
				String[] termAndDocId = inputs[0].split("@");
				String[] nAndN = inputs[1].split("@");
				if (termAndDocId.length == 2 && nAndN.length == 2) {
					String term = termAndDocId[0];
					String docId = termAndDocId[1];
					String n = nAndN[0];
					String N = nAndN[1];
				
					String newValue = docId + "@" + n + "@" + N + "@" + 1;
					context.write(new Text(term), new Text(newValue));
				}
			}			
	}
}
	
	

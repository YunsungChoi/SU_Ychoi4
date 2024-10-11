package stubs;
import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper; 


public class TFIDFMapper4 extends Mapper<LongWritable, Text , Text, DoubleWritable>{
	@Override
	public void map(LongWritable key, Text value, Context context) 
		throws IOException, InterruptedException{
		
			double NumDoc = 30; // Assumed to be known
			
			String[] inputs = value.toString().split("\t"); 
			if(inputs.length == 2) {
				String[] termAndDocId = inputs[0].split("@");
				String[] inputValue = inputs[1].toString().split("@"); 
				if (termAndDocId.length == 2 && inputValue.length == 3) {
					String term = termAndDocId[0];
					String docid = termAndDocId[1];
	
					String n = inputValue[0];
					String N = inputValue[1];
					String m = inputValue[2];
				
					double TF = Double.parseDouble(n) / Double.parseDouble(N);
					double IDF = Math.log(NumDoc / Double.parseDouble(m));
				
					context.write(new Text(term + "@" + docid), new DoubleWritable(TF * IDF));
				}
			}
			
			
	
			
			
	}
}
	
	

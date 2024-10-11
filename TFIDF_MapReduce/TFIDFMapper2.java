package stubs;
import java.io.IOException; 
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.mapreduce.Mapper; 


public class TFIDFMapper2 extends Mapper<LongWritable, Text , Text, Text>{
	@Override
	public void map(LongWritable key, Text value, Context context) 
		throws IOException, InterruptedException{
			String[] lines = value.toString().split("\t");
			if(lines.length == 2) {
				String[] termAndDocId = lines[0].split("@");
					if (termAndDocId.length == 2) {
						String term = termAndDocId[0];
						String docId = termAndDocId[1];
						String count = lines[1];
						context.write(new Text(docId), new Text(term +"@" + count));
					}
					
				
				}
	}
}
	
	

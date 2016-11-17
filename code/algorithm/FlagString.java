import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;
import org.apache.hadoop.io.WritableComparable;
public class FlagString implements WritableComparable {
	private String value;
	private int flag; // 标记 0:表示phone表 1：表示user表
	public FlagString() {
		super();
	}
	public FlagString(String value, int flag) {
		super();
		this.value = value;
		this.flag = flag;
	}
	public String getValue() {
		return value;
	}
	public void setValue(String value) {
		this.value = value;
	}

	public int getFlag() {
		return flag;
	}
	public void setFlag(int flag) {
		this.flag = flag;
	}
	public void write(DataOutput out) throws IOException {
		out.writeInt(flag);
		out.writeUTF(value);
	}

	public void readFields(DataInput in) throws IOException {
		this.flag = in.readInt();
		this.value = in.readUTF();
	}
	public int compareTo(FlagString o) {
		if (this.flag >= o.getFlag()) {
			if (this.flag > o.getFlag()) {
				return 1;
			}
		} else {
			return -1;
		}
		return this.value.compareTo(o.getValue());
	}
}

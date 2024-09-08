package lesson_04;

public class Course {

	private String name;
	private int ecs;
	
	public Course(String name,int ecs)
	{
		this.name=name;
		this.ecs=ecs;
	}
	
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getEcs() {
		return ecs;
	}
	public void setEcs(int ecs) {
		this.ecs = ecs;
	}
	
	
	
	
}

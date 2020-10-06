import java.util.*; 
  

public class LRUCache {
	
	Set<Integer> cache;
	int capacity;
	
	public LRUCache(int capacity) {
		this.capacity = capacity;
		this.cache = new LinkedHashSet<Integer>(capacity);
	}
	
	public boolean get(int key) {
		if(!cache.contains(key))
			return false;
		cache.remove(key);
		cache.add(key);
		return true;
	}
	
	public void refer(int x) {
		if(!get(x))
			put(x);
	}
    
	public void put(int x) {
		if(cache.contains(x))
			cache.remove(x);
		else if(cache.size()==capacity) {
			int firstKey = cache.iterator().next();
			cache.remove(firstKey);
		}
		cache.add(x);
	}
	public void display() 
    { 
        Iterator<Integer> itr = cache.iterator(); 
        while (itr.hasNext()) { 
            System.out.print(itr.next() + " "); 
        } 
    } 
	
    public static void main(String[] args) 
    { 
        LRUCache ca = new LRUCache(4); 
        ca.refer(1); 
        ca.refer(2); 
        ca.refer(3); 
        ca.refer(1); 
        ca.refer(4); 
        ca.refer(5); 
        ca.display(); 
    }    
}

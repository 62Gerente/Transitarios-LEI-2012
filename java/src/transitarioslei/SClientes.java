package transitarioslei;


/**
 * Class principal do projecto TransitÃ¡rios LEI
 * 
 * @author Andre Santos
 * @author Helena Alves
 * @author Ricardo Branco
 * @version LI III (Java)
 */

import java.io.*;
import java.util.*;
import java.util.TreeMap;
import java.io.PrintWriter;

public class SClientes extends Observable implements Serializable
{
    //variaveis de instancia
    
    private TreeMap<String,Cliente> clientes_nome;
    private TreeMap<Long,Cliente> clientes_nif;

    //costrutores
    
    /** Costructor vazio*/
    public SClientes(){
        this.clientes_nome = new TreeMap<String,Cliente>();
        this.clientes_nif = new TreeMap<Long,Cliente>();
    }
    
    public SClientes(Observer o){
        this.clientes_nome = new TreeMap<String,Cliente>();
        this.clientes_nif = new TreeMap<Long,Cliente>();
        addObserver(o);
    }
    
    /** Costructor por partes*/
    public SClientes(Collection<Cliente> clientes){
        this.set_Clientes(clientes);
    }
    
    /** Constructor de copia*/
    public SClientes(SClientes t){
        this.clientes_nome = new TreeMap<String,Cliente>(t.get_Clientes_nome());
        this.clientes_nif = new TreeMap<Long,Cliente>();
        
        Collection<Cliente> coll = this.clientes_nome.values();
        
        for (Cliente c : coll){
            this.clientes_nif.put(c.get_Nif(),c);
        }
    }
    
    // Metodos
    
        // Getters
    
    /** Metodo que devolve a lista de clientes por nome*/
    public Map<String,Cliente> get_Clientes_nome(){
        Map<String,Cliente> res =  new TreeMap<String,Cliente>();
        Collection<Cliente> coll = this.clientes_nome.values();
        
        for (Cliente c : coll)
            res.put(c.get_Nome(),c.clone());
            
        return res;
    }
    
    /** Metodo que devolve a lista de clientes por nif*/
    public Map<Long,Cliente> get_Clientes_nif(){
        Map<Long,Cliente> res =  new TreeMap<Long,Cliente>();
        Collection<Cliente> coll = this.clientes_nif.values();
        
        for (Cliente c : coll)
            res.put(c.get_Nif(),c.clone());
            
        return res;
    }
    
        //Setters
    
    /** Metodo que edita a estrutura de Clientes por nome*/
    public void set_Clientes(Collection<Cliente> clientes){
        this.clientes_nome = new TreeMap<String,Cliente>();
        this.clientes_nif = new TreeMap<Long,Cliente>();
        for(Cliente c :clientes){
            this.addCliente(c.clone());
        }
    }
    
    //EQUALS,CLONE,TOSTRING
    
    /** Metodo que verificar a igualdade de duas SClientes*/
    public boolean equals(Object o){
        if (o==this)
            return true;
        
        if((o==null) || (o.getClass() != this.getClass()))
            return false;
        
        SClientes c = (SClientes) o;
        return this.clientes_nif.equals(c.get_Clientes_nif());
    }
    
    /**Metodo clone*/
    public SClientes clone(){
        return new SClientes(this);
    }
    
    
    /**Metodo que imprime todos os clientes da estrutra*/
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("------------------CLIENTES------------------");
        sb.append(this.clientes_nif.toString() + "\n");
        return sb.toString();
    }
    
    
    //OUTROS METODOS
    
    /**Metodo que adiciona um cliente*/
    public boolean addCliente(Cliente c){
        Cliente cliente = c.clone();
        return addCliente_Nif(cliente) && addCliente_Nome(cliente);
    }
    
    /** Metodo que adiciona um cliente por nif*/    
    private boolean addCliente_Nif(Cliente c){ 
        if (this.clientes_nif.containsKey(c.get_Nif()))
            return false;
        else {
            this.clientes_nif.put(c.get_Nif(),c);
            return true;
        }
    }
    
    
    /** Metodo que adiciona um cliente por nome*/
    private boolean addCliente_Nome(Cliente c){
        if (this.clientes_nome.containsKey(c.get_Nome()))
            return false;
        else {
            this.clientes_nome.put(c.get_Nome(),c);
            return true;
        }
    }
    
    
    public void addAll(Collection<Cliente> coll){
        for (Cliente c : coll){
            Cliente cliente = c.clone();
            this.addCliente_Nome(cliente);
            this.addCliente_Nif(cliente);
        }
    }
    
    
    /**Metodo que adiciona varios clientes por Nif*/
    private void addClientes_Nif(Collection<Cliente> c){
        for(Cliente aux : c)
            this.addCliente_Nif(aux);
    }
    
    
    /**Metodo que adiciona varios clientes por Nome*/
     private void addClientes_Nome(Collection<Cliente> c){
        for(Cliente aux : c)
            this.addCliente_Nome(aux);
    }

    /**Metodo que procura um cliente*/
    public Cliente procura_Cliente(Cliente c){
        return this.clientes_nif.get(c.get_Nif());
    }
   
    /**Metodo que procura um cliente por nif*/
    public Cliente procura_ClienteNif(long nif){
        return this.clientes_nif.get(nif);
    }
    
    /**Metodo que procura um cliente por nome*/
    public Cliente procura_ClienteNome(String nome){
        return this.clientes_nome.get(nome);
    }

    /** Metodo que le os clientes de um ficheiro*/
    public void lerClientes(String fileName, int nrclientes) throws FileNotFoundException, IOException {
        BufferedReader read = new BufferedReader(new FileReader(fileName));
        
        while(read.ready() && nrclientes>0){
            String linha = read.readLine();
            StringTokenizer st = new StringTokenizer(linha,"|");
            
            Cliente cliente = new Cliente(Long.valueOf(st.nextToken()),st.nextToken(),st.nextToken(),st.nextToken());
            this.addCliente(cliente);
            nrclientes--;
        }
        read.close();
    }
    
    /** Metodo que escreve os clientes de um ficheiro*/
    public void escreveClientes(String fileName, int nrclientes) throws FileNotFoundException, IOException {
        PrintWriter print = new PrintWriter(fileName);
        
        Collection<Cliente> coll = this.clientes_nif.values();
        
        for(Cliente c : coll){
            print.println(c.get_Nif() + "|" + c.get_Nome() + "|" + c.get_Mail() + "|" + c.get_Morada());
            
            nrclientes--;
            if (nrclientes==0) break;
        }
        
        print.close();
    }
     public void lerobjClientes(String fileName) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream(fileName);
	ObjectInputStream ois = new ObjectInputStream(fis);
        
        this.clientes_nome = (TreeMap<String,Cliente>) ois.readObject();
        this.clientes_nif = (TreeMap<Long,Cliente>) ois.readObject();
        
        ois.close();
        fis.close();
    }
    
    /** Metodo que escreve os clientes de um ficheiro*/
    public void escreveobjClientes(String fileName) throws FileNotFoundException, IOException {
        FileOutputStream fos = new FileOutputStream(fileName);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        
        oos.writeObject(this.clientes_nome);
        oos.writeObject(this.clientes_nif);
        
        oos.close();
        fos.close();
    }
    
    /** Metodo que devolve o nr de clientes*/
    public int nrClientes(){
        return this.clientes_nome.size();
    }
    
    /** Metodo que devolve um vector com os clientes*/
    public Vector<String> get_Vector(){
        Vector<String> ret = new Vector<String>();
        
        Collection<String> coll = this.clientes_nome.keySet();
        
        for (String s : coll){
            ret.add(s);
        }
        return ret;
        
    }
 
    public Vector<String> parciais(String str){
        Vector<String> ret = new Vector<String>();
        
        Collection<String> coll = this.clientes_nome.keySet();
        
        for (String s : coll){
            if(s.contains(str))
            ret.add(s);
        }
        return ret;
        
    }
    
    /** Metodo que remove um cliente por nome*/
    public void remove_nome(String nome)
    {
        Cliente c = this.clientes_nome.get(nome);
        this.clientes_nif.remove(c.get_Nif());
        this.clientes_nome.remove(nome);
    }
    
    /** Metodo que remove um cliente por nome*/
    public void remove_nif(Long nif)
    {
        Cliente c = this.clientes_nif.get(nif);
        this.clientes_nome.remove(c.get_Nome());
        this.clientes_nif.remove(nif);
    }
    
}
package transitarioslei;

/**
 * Classe que descreve uma Localidade
 * 
 * @author Andre Santos
 * @author Helena Alves
 * @author Ricardo Branco
 * @version LI III (Java)
 */

import java.io.Serializable;
import java.util.*;
import java.util.Iterator;
import java.util.TreeSet; 

public class Localidade implements Serializable
{
    //macros
    
    private static final String def_codigopostal = "";
    private static final String def_nome = "";
   
    //variaveis de instancia
    
    private String codigopostal;
    private String nome;
    private TreeMap<String,Ligacao> ligacoes;

    //costrutores
    
    /** Costructor vazio*/
    public Localidade(){
        this.codigopostal = def_codigopostal;
        this.nome = def_nome;
        this.ligacoes = new TreeMap<String,Ligacao>();
    }
    
    /** Costructor por partes*/
        public Localidade(String codigopostal, String nome, Collection<Ligacao> ligacoes){
        this.codigopostal = codigopostal;
        this.nome = nome;
        this.set_Ligacoes(ligacoes);
    }

    /** Costrutor por partes, com codigo postal e nome da localidade*/
    public Localidade(String codigopostal, String nome){
        this.codigopostal = codigopostal;
        this.nome = nome;
        this.ligacoes = new TreeMap<String,Ligacao>();
    }

    /** Constructor de copia*/
    public Localidade(Localidade l){
        this.codigopostal = l.get_Codigopostal();
        this.nome = l.get_Nome();
        this.ligacoes = new TreeMap<String,Ligacao>(l.get_Ligacoes());
    }

    
    //metodos
        
        //getters

    /** Metodo que devolve o codigo postal da localidade*/
    public String get_Codigopostal(){
        return this.codigopostal;
    }
    
    /** Metodo que devolve o nome da localidade*/
    public String get_Nome(){
        return this.nome;
    }

    /** Metodo que devolve as ligacoes da localidade*/
    public Map<String,Ligacao> get_Ligacoes(){
        Collection<Ligacao> coll = this.ligacoes.values();
        Map<String,Ligacao> res = new TreeMap<String,Ligacao>();
        
        for(Ligacao l : coll)
            res.put(l.get_Localidaded(),l.clone());   
                
        return res; 
    }
    
        //setters

    /** Metodo que altera o codigopostal de uma localidae*/
    public void set_codigopostal(String codigopostal){
        this.codigopostal = codigopostal;
    }

    /** Metodo que altera o nome de uma localidade*/
    public void set_Nome(String nome){
        this.nome =  nome;
    }

    /** Metodo que altera a lista de ligacoes*/
    public void set_Ligacoes(Collection<Ligacao> ligacoes){
        this.ligacoes = new TreeMap<String,Ligacao>();
        this.addLigacoes(ligacoes);
    }
    
        //equals,toString,clone,hashCode
    
    /** Metodo que verifica se duas localidades sao iguais*/
    @Override
    public boolean equals(Object o)
    {
        if (this == o)
            return true;
        
        if ((o==null) || (o.getClass() != this.getClass()))
            return false;

        Localidade l = (Localidade) o;
        return this.codigopostal.equals(l.get_Codigopostal());

    }

    /** Metodo que devolve uma localidade em String*/
    @Override
    public String toString(){
        StringBuilder sn = new StringBuilder();
        sn.append("CODIGO POSTAL: " + this.codigopostal + "\n");
        sn.append("NOME: " + this.nome + "\n");
        sn.append("LIGACOES DIRECTAS: " + this.ligacoes.toString());
        return sn.toString();
    }

    /** Metodo que devolve um clone da localidade*/
    @Override
    public Localidade clone(){
        return new Localidade(this);
    }
    
    /** MÃ©todo que devolve o hash de uma localidade*/
    @Override
    public int hashCode(){
        return this.codigopostal.hashCode();
    }
    
        // Outros Metodos
        
    /** Metodo que compara duas localidades*/
    public int comparTo(Localidade l){
        return this.codigopostal.compareTo(l.get_Codigopostal());
    }
        
    /** Metodo que devolve o numero de ligacoes de uma localidade */    
    public int nrligacoes(){
        return this.ligacoes.size();
    }
    
    /** Metodo que verifica se a localidade tem ligacoes*/
    public boolean haligacoes(){
        return this.nrligacoes() > 0;
    }
    
    /** Metodo que verifica se a localidade tem uma ligacao com outra localidade*/
    public boolean haligacao(Localidade l){
        return this.ligacoes.containsKey(l.get_Nome());
    }
    
    /** Metodo que adiciona uma ligaÃ§Ã£o a localidade*/
    public boolean addLigacao(Ligacao l){
       if (this.ligacoes.containsKey(l.get_Localidaded()))
           return false;
       else{
           this.ligacoes.put(l.get_Localidaded(),l.clone());
           return true;
        }
    }
    
    /** Metodo que adiciona um conjunto de ligaÃ§Ãµes*/
    public void addLigacoes(Collection<Ligacao> ligacoes){
        for(Ligacao l : ligacoes)
            this.addLigacao(l.clone());
    }
    
    /** Metodo que remove uma ligaÃ§Ã£o da localidade*/
    public boolean removeLigacao(Ligacao l){
       if (this.ligacoes.containsKey(l.get_Localidaded())){
           this.ligacoes.remove(l.get_Localidaded());
           return true;
        }
       else
           return false;
    }
    
    /** Metodo que procura ligacao por nome*/
    public Ligacao procuraLig(String nome){
        return this.ligacoes.get(nome);
    }
}

package transitarioslei;

/**
 * Classe que descreve um Cliente
 * 
 * @author Andre Santos
 * @author Helena Alves
 * @author Ricardo Branco
 * @version LI III (Java)
 */

import java.io.Serializable;
import java.util.*;
import java.util.Iterator;

public class Cliente implements Serializable
{
    //macros
    
    private static final long def_nif = -1;
    private static final String def_nome = "";
    private static final String def_mail = "";
    private static final String def_morada = "";

    // variaveis de instancia
    
    private long nif;
    private String nome;
    private String mail;
    private String morada;
    
    // costrutores
    
    /** Costructor vazio*/
    public Cliente(){
       this.nif = def_nif;
       this.nome = def_nome;
       this.mail = def_mail;
       this.morada = def_morada;  
    }

    /** Costructor por partes*/
    public Cliente(long nif, String nome, String mail, String morada){
        this.nif = nif;
        this.nome = nome;
        this.morada = morada;
        this.mail = mail;
    }

    /** Costructor por copia*/
    public Cliente(Cliente c){
        this.nif = c.get_Nif();
        this.nome = c.get_Nome();
        this.mail = c.get_Mail();
        this.morada = c.get_Morada();
    }
    
    //metodos
    
        //getters

    /** Metodo que devolve o NIF do cliente*/
    public long get_Nif(){
        return this.nif;
    }
    
    /** Metodo que devolve o nome do cliente*/
    public String get_Nome(){
        return this.nome;
    }
    
    /** Metodo que devolve a morada do cliente*/
    public String get_Morada(){
        return this.morada;
    }
    
    /** Metodo que devolve o mail do cliente*/
    public String get_Mail(){
        return this.mail;
    }
    
    /** Metodo que altera o nif do cliente*/
    public void set_Nif(long nif){
        this.nif = nif;
    }
    
    /** Metodo que altera o nome do cliente*/
    public void set_Nome(String nome){
        this.nome = nome;
    }
    
    /** Metodo que altera a morada do cliente*/
    public void set_Morada(String morada){
        this.morada = morada;
    }
    
    /** Metodo que altera o mail do cliente*/
    public void set_Mail(String mail){
        this.mail = mail;
    }
    
        //equals,toString,clone,hashCode
        
    /** Metodo que verifica se dois clientes sao iguais*/
    @Override
    public Cliente clone(){
        return new Cliente(this);
    }
    
    /** Metodo que verifica se dois clientes sao iguais*/
    @Override
    public boolean equals(Object o){
        if (o==this)
            return true;
        
        if((o==null) || (o.getClass() != this.getClass()))
            return false;
        
        Cliente c = (Cliente) o;
        return (this.nif == c.get_Nif() || this.nome.equals(c));
    }
    
    /** Metodo que representa um cliente numa string*/
    @Override
    public String toString(){
        StringBuilder sn = new StringBuilder();
        sn.append("NIF: "+this.nif+"\n");
        sn.append("NOME: "+this.nome+"\n");
        sn.append("MORADA: "+this.morada+"\n");
        sn.append("MAIL: "+this.mail+"\n");    
        return sn.toString();
    }
    
    /** MÃ©todo que devolve o hash de um cliente*/
    @Override
    public int hashCode(){
        return (int)this.nif;
    }
    
        // outros metodos    
    
    /** Metodo que compara clientes pelo NIF*/
    public int compareTo(Cliente c){
        if(c.equals(this))
            return 0;
        else if (this.nif > c.get_Nif())
            return 1;
        else 
            return -1;
    }
    
    /** Metodo que compara clientes pelo nome*/
    public int compareNome(Cliente c){
        return  this.nome.compareTo(c.get_Nome());
    }
}
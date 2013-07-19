package transitarioslei;

/**
 * Classe que descreve uma Ligacao
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

public class Ligacao implements Serializable
{
    //macros
    
    private static final String def_localidaded = "";
    private static final double def_distancia = -1;
    private static final double def_taxas = -1;

    //variaveis de instancia
    
    private String localidaded;
    private double distancia;
    private double taxas; 

    //costrutores
    
    /** Costructor vazio*/
    public Ligacao(){
        this.localidaded = def_localidaded;
        this.distancia = def_distancia;
        this.taxas = def_taxas;  
    }
    
    /** Costructor por partes*/
    public Ligacao(String localidaded, double distancia, double taxas){
        this.localidaded = localidaded;
        this.distancia = distancia;
        this.taxas = taxas;
    }

    /** Constructor de copia*/
    public Ligacao(Ligacao l){
        this.localidaded = l.get_Localidaded();
        this.distancia = l.get_Distancia();
        this.taxas = l.get_Taxas();
    }

    
    //metodos
        
        //getters

    /** Metodo que devolve a localidade de destino da ligacao*/
    public String get_Localidaded(){
        return this.localidaded;
    }
    
    /** Metodo que devolve a distancia da ligacao*/
    public double get_Distancia(){
        return this.distancia;
    }
    
    /** Metodo que devolve as taxas da ligacao*/
    public double get_Taxas(){
        return this.taxas;
    }

        //setters
        
    /** Metodo que altera a localidade de destino da ligacao*/
    public void set_Localidaded(String localidaded){
        this.localidaded = localidaded;
    }
    
    /** Metodo que altera a distancia da ligacao*/
    public void set_Distancia(double distancia){
        this.distancia = distancia;
    }
    
    /** Metodo que altera as taxas da ligacao*/
    public void set_Taxas(double taxas){
        this.taxas = taxas;
    }
    
        //toString,clone,equals,hashCode
    
    /** Metodo que devolve um clone da Ligacao*/
    public Ligacao clone(){
        return new Ligacao(this);
    }
    
    /** Metodo que representao uma ligacao sob a forma de String*/
    public String toString(){
        StringBuilder s = new StringBuilder();
        s.append ("LOCALIDADE DE DESTINO: " +  localidaded);
        s.append ("DISTANCIA: " + distancia);
        s.append ("TAXAS: " + taxas);
        return s.toString();
    }
    
    /** Metodo que verifica a igualdade de duas ligacoes*/
    public boolean equals(Object o){
        if (o == this)
            return true;
        if (o == null || o.getClass() != this.getClass())
            return false;
        
        Ligacao l = (Ligacao) o;
        return (this.equals(l.get_Localidaded()));
    }
    
    /** Metodo que devolve o hash de uma ligaÃ§Ã£o*/
    
    public int hashCode(){
        return this.localidaded.hashCode();
    }

        // outros metodos
        
     /** Metodo que compara duas ligacoes */
    public int comparTo(Ligacao l){
        return this.localidaded.compareTo(l.get_Localidaded());
    }   

    /** Metodo que compara duas ligacoes */
    public int compar(Ligacao l){
        if (this.distancia < l.get_Distancia())
            return -1;
        else if (this.distancia > l.get_Distancia())
            return 1;
        else if (this.taxas < l.get_Taxas())
            return -1;
        else if (this.taxas > l.get_Taxas())
            return 1;
        else 
            return 0;
    }
}

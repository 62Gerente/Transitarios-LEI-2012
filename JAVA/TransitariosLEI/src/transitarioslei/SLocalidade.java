package transitarioslei;

/**
 * Classe principal do projecto Transitarios LEI
 * 
 * @author Andre Santos
 * @author Helena Alves
 * @author Ricardo Branco
 * @version LI III (Java)
 */

import java.io.*;
import java.util.*;

public class SLocalidade extends Observable implements Serializable
{

    public static final int _VIS_WHITE = -1;
    public static final int _VIS_GREY = 0;
    public static final int _VIS_BLACK = 1 ;
    
    //variaveis de instancia
    private TreeMap<String,Localidade> localidades;
    //costrutores
    
    /** Costructor vazio*/
    public SLocalidade(){
       this.localidades = new TreeMap<String,Localidade>();
    }
    
    public SLocalidade(Observer o){
       this.localidades = new TreeMap<String,Localidade>();
       addObserver(o);
    }
    
    /** Costructor por partes*/
    public SLocalidade(Collection<Localidade> localidades){
        this.set_CLocalidades(localidades);
    }
    
    /** Constructor de copia*/
    public SLocalidade(SLocalidade t){
         this.localidades = new TreeMap<String,Localidade>(t.get_Localidades());
    }
    
    // Metodos
    
        // Getters
 
    
    /** Metodo que devolve a estrutura de Localidades*/
    public Map<String,Localidade> get_Localidades(){
        Map<String,Localidade> res =  new TreeMap<String,Localidade>();
        Collection<Localidade> coll = this.localidades.values();
        
        for (Localidade l : coll)
            res.put(l.get_Nome(),l.clone());
            
        return res;
    }
    
    //Setters

    /**Metodo que edita a estrutura de Localidades*/  
    public void set_CLocalidades(Collection<Localidade> localidades){
        this.localidades = new TreeMap<String,Localidade>();
        this.addLocalidades(localidades);
    }
    
    //Clone,equals,toString
    
    /** Metodo que verifica se duas SLocalidades sÃ£o iguais*/
    public boolean equals(Object o){
        if (this==o)
            return true;
        
        if ((o==null)||(o.getClass() != this.getClass()))
            return false;
        
        SLocalidade sl = (SLocalidade) o;
        return this.localidades.equals(sl.get_Localidades());
    }
    
    /** Metodo que devolve um clone de uma SLocalidade*/
    public SLocalidade clone(){
        return new SLocalidade(this);
    }

    /** Metodo que representa uma SLocalidade como uma String*/
    public String toString(){
        StringBuilder s = new StringBuilder();
        s.append("--------LOCALIDADES--------");
        s.append(this.localidades.toString());
        return s.toString();
    }
    
       //LOCALIDADES

    
    /**Metodo que adiciona uma localidade na estrutura*/ 
    public boolean addLocalidade(Localidade localidade){
        if (this.localidades.containsKey(localidade.get_Nome()))
            return false;
        else {
            this.localidades.put(localidade.get_Nome(),localidade.clone());
            return true;
        }
    }
    
    
    /**Metodo que adiciona varias localidades na estrutura*/ 
    public void addLocalidades(Collection<Localidade> localidades){
        for(Localidade l :localidades)
            this.addLocalidade(l.clone());
    }
    
    
    /**Metodo que remove uma localidadade da estrutura de localidades*/
    public boolean removeLocalidade(Localidade localidade){
        if(this.localidades.containsKey(localidade.get_Nome())){
            Ligacao lig = new Ligacao(localidade.get_Nome(),0,0);
            Collection<Localidade> coll = this.localidades.values();
            
            for(Localidade aux : coll)
                aux.removeLigacao(lig);
            
            this.localidades.remove(localidade.get_Nome());
            return true;
        }
        return false;
    }
    
    /** Metodo que adiciona uma ligaÃ§Ã£o*/
    public boolean addLigacao(Ligacao ligacao, String partida){
        if(this.localidades.containsKey(partida)){
            Localidade aux = this.localidades.get(partida);
            return aux.addLigacao(ligacao.clone());
        }
        return false;
    }
    
    /**Metdo que remove uma ligaÃ§Ã£o*/
    public boolean removeligacao(Ligacao ligacao, String partida){
        if(this.localidades.containsKey(partida)){
            Localidade aux = this.localidades.get(partida);
            return aux.removeLigacao(ligacao);
        }
        return false;
    }
    
    /** Metodo que le os clientes de um ficheiro*/
    public void lerLocalidades(String fileLocalidades, String fileLigacoes, int nrlocalidades) throws FileNotFoundException, IOException {
        BufferedReader readLoc = new BufferedReader(new FileReader(fileLocalidades));
        BufferedReader readLig = new BufferedReader(new FileReader(fileLigacoes));
        int nrligacoes;
        
        while(readLoc.ready() && nrlocalidades>0){

            String linhaLoc = readLoc.readLine();
            StringTokenizer stLoc = new StringTokenizer(linhaLoc,"|");
            nrligacoes = stLoc.countTokens()-2;
            Localidade localidade = new Localidade(stLoc.nextToken(),stLoc.nextToken());
            
            while (nrligacoes>0 && readLig.ready()){
                String linhaLig = readLig.readLine();
                StringTokenizer stLig = new StringTokenizer(linhaLig,"|");
                stLig.nextToken();
                Ligacao lig = new Ligacao(stLig.nextToken(),Double.valueOf(stLig.nextToken()),Double.valueOf(stLig.nextToken()));
                localidade.addLigacao(lig);
                nrligacoes--;
            }
            this.addLocalidade(localidade);
            nrlocalidades--;
        }
        readLoc.close();
        readLig.close();
    }
    
    /** Metodo que escreve os clientes num ficheiro*/
    public void escreveLocalidades(String fileLocalidades, String fileLigacoes, int nrlocalidades) throws FileNotFoundException, IOException {
        PrintWriter printloc = new PrintWriter(fileLocalidades);
        PrintWriter printlig = new PrintWriter(fileLigacoes);
        
        Collection<Localidade> coll = this.localidades.values();
        
        for(Localidade l : coll){
            printloc.print(l.get_Codigopostal() + "|" + l.get_Nome());
            
            Map<String,Ligacao> ligacoes = l.get_Ligacoes();
            int nrligacoes = ligacoes.size();
            
            Collection<Ligacao> colllig = ligacoes.values();
            
            for(Ligacao lig : colllig){
                printloc.print("|1");
                printlig.println(l.get_Codigopostal() + "|" + lig.get_Localidaded() + "|" + lig.get_Distancia() + "|" + lig.get_Taxas());
            }
            printloc.print("\n");
            
            nrlocalidades--;
            if (nrlocalidades==0) break;
        }
        
        printloc.close();
        printlig.close();
    }
    
    /** Metodo que le os clientes de um ficheiro*/
    public void lerobjLocalidades(String fileLocalidades) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream fisloc = new FileInputStream(fileLocalidades);
	ObjectInputStream oisloc = new ObjectInputStream(fisloc);

        this.localidades = (TreeMap<String,Localidade>) oisloc.readObject();
        
        oisloc.close();
        fisloc.close();
            
    }
    
    /** Metodo que escreve os clientes num ficheiro*/
    public void escreveobjLocalidades(String fileLocalidades) throws FileNotFoundException, IOException {
        FileOutputStream fosloc = new FileOutputStream(fileLocalidades);
        ObjectOutputStream oosloc = new ObjectOutputStream(fosloc);

        oosloc.writeObject(this.localidades);
        
        oosloc.close();
        fosloc.close();
    }
    
    
    /** Metodo que devolve o nr de localidades*/
    public int nrLocalidades(){
        return this.localidades.size();
    }
    
    /** Metodo que procura localidades por nome*/
    public Localidade procuraLoc(String nome){
        return this.localidades.get(nome).clone();
    }
    
    /** Metodo que procura as ligacoes de uma localidade*/
    public Map<String,Ligacao> procuraLigacoes(String localidade){
        return this.localidades.get(localidade).get_Ligacoes();
    }
    
    /** Metodo que devolve um vector com as localidades*/
    public Vector<String> get_Vector(){
        Vector<String> ret = new Vector<String>();
        
        Collection<String> coll = this.localidades.keySet();
        
        for (String s : coll){
            ret.add(s);
        }
        return ret;
        
    }
    
    public Vector<String> parciais(String str){
        Vector<String> ret = new Vector<String>();
        
        Collection<String> coll = this.localidades.keySet();
        
        for (String s : coll){
            if (s.contains(str))
                ret.add(s);
        }
        return ret;
        
    }
    /** Metodo que calcula o nr localidades entre 2 localidades*/
    public int distancia(String partida, String destino, Vector<String> caminho){
        HashMap<String,DijElem> elementos = new HashMap<String,DijElem>((int)(this.localidades.size()*1.4));
        
        DijElem elemAct;
        Localidade localAct;
        
        elemAct = new DijElem(partida, 0, "", _VIS_GREY);
        
        elementos.put(elemAct.get_Nome(), elemAct.clone());
        
        int greycount = 1;
        while (greycount > 0){
            elemAct = null;
            elemAct = verificaproxnodo(elementos);
            
            if (elemAct==null) return -1;
            
            localAct = this.localidades.get(elemAct.get_Nome());
            
            if (localAct==null) return -1;
            
            greycount = distancia_aux(localAct.get_Ligacoes(),elemAct,elementos,greycount);
            
            elemAct.set_Vis(_VIS_BLACK);
            
            if(elemAct.get_Nome().equals(destino)){
                caminho.add(destino);
                
                DijElem pcaminho = elemAct;
                while(!pcaminho.get_Pai().equals("")){
                    caminho.add(pcaminho.get_Pai());
                    pcaminho = elementos.get(pcaminho.get_Pai());
                }
                
                return elemAct.get_Nrlocalidades();
            }
            
            greycount--;

        }
        return -1;
    }
    
    private DijElem verificaproxnodo(HashMap<String,DijElem> elementos){
        DijElem prox = null;
        
        Collection<DijElem> coll = elementos.values();
        
        for(DijElem elem : coll){
            if(elem.get_Vis() != _VIS_BLACK && (prox==null || prox.get_Nrlocalidades() > elem.get_Nrlocalidades())){
                prox = elem;
            }
        }
        
        return prox;
    }
    
    private int distancia_aux(Map<String,Ligacao> ligacoes, DijElem elemAct,HashMap<String,DijElem> elementos,int greycount){
        Collection<Ligacao> coll = ligacoes.values();
        int grey = greycount;
        
        for(Ligacao lig : coll){
            DijElem target = elementos.get(lig.get_Localidaded());
            

            if (target!=null && (target.get_Vis() != _VIS_BLACK) && (target.get_Nrlocalidades() > (elemAct.get_Nrlocalidades()+1))){
                target.set_Nrlocalidades(elemAct.get_Nrlocalidades()+1);
                target.set_Pai(elemAct.get_Nome());
            }
            else if(target==null){
                target = new DijElem(lig.get_Localidaded(), elemAct.get_Nrlocalidades()+1, elemAct.get_Nome(), _VIS_GREY);
                
                grey++;
                
                elementos.put(lig.get_Localidaded(), target.clone());
            }
        }
        
        return grey;
    }
}

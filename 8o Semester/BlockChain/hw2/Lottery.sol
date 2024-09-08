pragma solidity ^0.5.9;

contract Lottery{

    struct Item{
        uint itemId;
        uint[] itemTokens; 
    }

    struct Person{
        uint personId;
        address addr;
        uint remainingTokens;
    }

    event Winner(address winner, uint id, uint round);

    uint public roundId;
    enum Stage{Init, Reg, Bid, Done}
    Stage public stage; 

    //Person details
    mapping(address => Person) tokenDetails;
    Person[] public bidders;

    //List of all the items
    Item[] public items; 
    address[] public winners; //List of winner for each item

    //Has to be payable since contract creator can withdraw from the contract balance
    address payable public beneficiary;

    //Creates new item array of size itemCount
    constructor(uint itemCount) public payable{
        beneficiary = msg.sender;
        roundId = 0;
        for(uint i=0; i<itemCount; i++){
            items.push(Item({itemId:i, itemTokens:new uint[](0)}));
        }
        stage = Stage.Init; 
    }


    //Add sender to bidders and token details -> increase bidderCount -> add a slot on each items itemTokens for new bidder
    function register() public payable minValue() notBeneficiary() notRegistered() onlyInStage(Stage.Reg){
        bidders.push(Person({personId:bidders.length, addr:msg.sender, remainingTokens:5}));
        tokenDetails[msg.sender] = bidders[bidders.length-1];

        for(uint i = 0; i<items.length; i++){
            items[i].itemTokens.push(0); 
        }
    }
    

    function bid(uint itemid, uint count) public payable itemsExists(itemid) hasVotes(count) onlyInStage(Stage.Bid) {
        //Reduce the remaining tokens
        tokenDetails[msg.sender].remainingTokens -= count; 
        bidders[tokenDetails[msg.sender].personId].remainingTokens -=count;
        //Add to item slot
        items[itemid].itemTokens[tokenDetails[msg.sender].personId] += count; 
    }


    function revealWinners() public onlyBy(beneficiary) noWinners() onlyInStage(Stage.Done){
        winners = new address[](items.length); //Init the winners array
        for(uint i=0; i<items.length; i++){
            uint sum = 0;
            for(uint j = 0; j<items[i].itemTokens.length; j++){ //Sum the tokens deposited for this item
                sum += items[i].itemTokens[j];
            }

            if(sum != 0){ //If item has tokens
                uint rand = random() % sum; 
                for(uint j = 0; j<bidders.length; j++){
                    if(rand <= items[i].itemTokens[j] && items[i].itemTokens[j]!=0){ 
                        winners[i] = bidders[j].addr;
                        emit Winner(winners[i], items[i].itemId, roundId);
                        break;
                    }
                    else{
                        rand -=items[i].itemTokens[j]; 
                    }
                }
            }
        }
    }

    

    function reset(uint newItemCount) public onlyBy(beneficiary){ 
        while( items.length>0){ //Remove items
            items.pop();
        }        

        for(uint i=0; i<newItemCount; i++){ //Add new items
            items.push(Item({itemId:i, itemTokens:new uint[](0)}));
        }        

        while(bidders.length>0){ //Delete bidders
            bidders.pop();
        }
        winners= new address[](0); //New winners array

        stage = Stage.Init; //Reverts back to init
        roundId++; 
    }

    function advanceStage() public onlyBy(beneficiary){
        if(stage == Stage.Init){stage = Stage.Reg;}
        else if(stage == Stage.Reg){stage = Stage.Bid;}
        else if(stage == Stage.Bid){stage = Stage.Done;}
    }

    //Random number generator
    function random() private view returns(uint){ 
        return uint(keccak256(abi.encodePacked(block.difficulty, now)));
    }

    function withdraw() public payable onlyBy(beneficiary){
        beneficiary.transfer(address(this).balance);
    }

    modifier itemsExists(uint id){
        if(id>=items.length) {//Id bigger than the ammount of items we have
            revert();
        }
        else{
            _;
        }
    }

    modifier onlyBy(address addr){
        if(msg.sender != addr){
            revert();
        }
        _;
    }

    modifier minValue(){
        if(msg.value <0.01 ether){ 
            revert();
        }
        _;
    }

    modifier voteExists(){
        bool flag = false;
        for(uint i = 0; i<items.length; i++){
            for(uint j = 0; j<items[i].itemTokens.length; j++){
                if(items[i].itemTokens[j] != 0){
                    flag = true;
                    break; //No need to check further
                }
            }
        }

        if(flag){
            _;
        }
        else{
            revert();
        }
    }

    modifier hasVotes(uint count){
        if(tokenDetails[msg.sender].remainingTokens <count){
            revert();
        }
        _;
    }

    modifier notBeneficiary(){
        if(msg.sender == beneficiary){
            revert();
        }
        _;
    }

    modifier notRegistered(){ //Sender not already registered
        for(uint i = 0; i<bidders.length; i++){
            if(bidders[i].addr == msg.sender){
                revert();
            }
        }
        _;
    }

    modifier noWinners(){ //If item without winners
        if(winners.length!=0){
            bool flag = false;
            for(uint i=0;i<winners.length;i++){
                if(winners[i] == address(0)){
                    flag = true;
                    break;
                }
            }

            if(flag){
                _;
            }
            else{
                revert();
            }
        }
        else{
            revert();
        }
    }

    modifier onlyInStage(Stage s){
        if(stage!=s){
            revert();
        }
        _;
    }

    //(id, tokens, addr)
    function getPersonDetails(uint id) public view returns(uint, uint, address){
        return(id, bidders[id].remainingTokens, bidders[id].addr);
    }
}